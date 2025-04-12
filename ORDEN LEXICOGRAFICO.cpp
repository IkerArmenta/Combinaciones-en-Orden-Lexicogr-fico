#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

unsigned long long binomial_coefficient(int n, int r) {
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    unsigned long long resultado = 1;
    for (int i = 1; i <= r; i++) {
        resultado = resultado * (n - i + 1) / i;
    }
    return resultado;
}

void generate_and_write_combinations(int n, int r, ofstream &file, unsigned long long &count) {
    if (r == 0) {
        file << "\n";
        count++;
        return;
    }
    
    vector<int> combinacion(r);
    for (int i = 0; i < r; i++) {
        combinacion[i] = i + 1;
    }
    
    while (true) {
        for (int i = 0; i < r; i++) {
            file << combinacion[i];
            if (i < r - 1)
                file << ",";
        }
        file << "\n";
        count++;
        
        int i;
        for (i = r - 1; i >= 0; i--) {
            if (combinacion[i] < n - r + i + 1)
                break;
        }
        if (i < 0)
            break;
            
        combinacion[i]++;
        for (int j = i + 1; j < r; j++) {
            combinacion[j] = combinacion[j - 1] + 1;
        }
    }
}

bool is_valid_input(int n, int r) {
    return n >= 1 && r >= 0 && r <= n;
}

int main() {
    int n, r;
    
    while (true) {
        cout << "Ingrese el valor de n (>= 1): ";
        cin >> n;
        cout << "Ingrese el valor de r (>= 0 y <= n): ";
        cin >> r;
        if (is_valid_input(n, r))
            break;
        else
            cout << "Entrada no válida. Por favor intente de nuevo.\n";
    }
    
    string nombreArchivo = "combinaciones_n" + to_string(n) + "_r" + to_string(r) + ".csv";
    
    ofstream file(nombreArchivo);
    if (!file.is_open()) {
        cerr << "No se puede abrir el archivo para escribir: " << nombreArchivo << "\n";
        return 1;
    }
    
    unsigned long long contador = 0;
    generate_and_write_combinations(n, r, file, contador);
    file.close();
    
    unsigned long long conteoTeorico = binomial_coefficient(n, r);
    
    cout << "\nNúmero total de combinaciones generadas: " << contador << endl;
    cout << "Número teórico de combinaciones C(" << n << ", " << r << "): " << conteoTeorico << endl;
    cout << "Los conteos " << (contador == conteoTeorico ? "coinciden." : "NO coinciden.") << endl;
    cout << "Archivo CSV guardado con el nombre: " << nombreArchivo << endl;
    
    return 0;
}