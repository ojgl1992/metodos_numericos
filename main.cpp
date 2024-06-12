// método de bisección
#include <iostream>
#include <cmath>
using namespace std;

// Función que define la ecuación polinómica cuya raíz queremos encontrar
// Esta función representa la ecuación ax^2 + bx + c = 0
double f(double x, double a, double b, double c) {
    // Calcula y retorna el valor de la función f(x) = ax^2 + bx + c
    return (a * x * x) + (b * x) + c;
}

// Función que implementa el método de bisección
// Parámetros:
// - a_coef: coeficiente a de la ecuación ax^2 + bx + c
// - b_coef: coeficiente b de la ecuación ax^2 + bx + c
// - c_coef: coeficiente c de la ecuación ax^2 + bx + c
// - a: extremo izquierdo del intervalo inicial
// - b: extremo derecho del intervalo inicial
// - tol: tolerancia para el criterio de convergencia
// - max_iter: número máximo de iteraciones permitidas
void biseccion(double a_coef, double b_coef, double c_coef, double a, double b, double tol, int max_iter) {
    double c;  // Punto medio del intervalo actual
    int iter = 0;  // Contador de iteraciones

    // Verifica si la función cambia de signo en el intervalo [a, b]
    if ((f(a, a_coef, b_coef, c_coef) * f(b, a_coef, b_coef, c_coef)) >= 0) {
        cout << "La función debe cambiar de signo en el intervalo [a, b]." << endl;
        return;  // Si no cambia de signo, termina el proceso
    }

    // Imprime la cabecera de la tabla de resultados
    cout << "Iteración\t a\t\t b\t\t c\t\t f(c)" << endl;
    cout << "-----------------------------------------------------------" << endl;

    // Bucle que ejecuta el método de bisección
    while (((b - a) / 2.0) > tol && iter < max_iter) {
        // Calcula el punto medio del intervalo actual
        c = (a + b) / 2.0;

        // Imprime los valores actuales de a, b, c y f(c)
        cout << iter + 1 << "\t\t" << a << "\t" << b << "\t" << c << "\t" << f(c, a_coef, b_coef, c_coef) << endl;

        // Verifica si c es una raíz exacta
        if (f(c, a_coef, b_coef, c_coef) == 0.0) {
            break;  // Si f(c) es 0, c es la raíz exacta
        } else if ((f(c, a_coef, b_coef, c_coef) * f(a, a_coef, b_coef, c_coef)) < 0) {
            b = c;  // Si f(c) y f(a) tienen signos opuestos, la raíz está en [a, c]
        } else {
            a = c;  // Si f(c) y f(b) tienen signos opuestos, la raíz está en [c, b]
        }

        iter++;  // Incrementa el contador de iteraciones
    }

    // Imprime el resultado final: la raíz aproximada y el número de iteraciones realizadas
    cout << "La raíz aproximada después de " << iter << " iteraciones es " << c << " con una tolerancia de " << tol << "." << endl;
}

// Función principal del programa
int main() {
    double a_coef, b_coef, c_coef;  // Coeficientes de la ecuación ax^2 + bx + c = 0
    double a, b, tol;  // Variables para los extremos del intervalo, la tolerancia
    int max_iter;  // Variable para el número máximo de iteraciones

    // Solicita al usuario que ingrese los coeficientes de la ecuación
    cout << "Ingrese el coeficiente a: ";
    cin >> a_coef;
    cout << "Ingrese el coeficiente b: ";
    cin >> b_coef;
    cout << "Ingrese el coeficiente c: ";
    cin >> c_coef;

    // Solicita al usuario que ingrese los valores de a, b, la tolerancia y el número máximo de iteraciones
    cout << "Ingrese el valor de a (extremo izquierdo del intervalo): ";
    cin >> a;
    cout << "Ingrese el valor de b (extremo derecho del intervalo): ";
    cin >> b;
    cout << "Ingrese la tolerancia: ";
    cin >> tol;
    cout << "Ingrese el número máximo de iteraciones: ";
    cin >> max_iter;

    // Llama a la función de bisección con los valores ingresados por el usuario
    biseccion(a_coef, b_coef, c_coef, a, b, tol, max_iter);

    return 0;  // Termina el programa
}
