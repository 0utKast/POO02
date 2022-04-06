
#if 0 
#include <iostream>
#include <string>

class Estudiante
{
public:
    std::string m_nombre{};
    int m_id{};
    double m_nota{};

    // Imprime la información del empleado
    void imprimir()
    {
        std::cout << "Nombre: " << m_nombre <<
            "  Id: " << m_id <<
            "  Nota: " << m_nota << '\n';
    }
};

int main()
{
    // Instanciamos dos estudiantes
    Estudiante juan { "Juan", 1, 7.4};
    Estudiante ana{ "Ana", 2, 8.7 };

    // Imprime la información de los estudiantes
    juan.imprimir();
    ana.imprimir();

    return 0;
}



#include <iostream>

int funcionB()
{
    funcionA();
}

int funcionA()
{
    funcionB();
}



int main()
{
    funcionA();


}


#include <iostream>
class Comprobar
{
public:
    void funcionA() 
    {
		std::cout <<"Estamos en funcionA que llama a funcionB" << std::endl;
        funcionB(); //correcto, aunque funciónB aún no esté definida
    } 
    void funcionB() 
    {
		std::cout <<"Estamos en funcionB que llama a funcionA" << std::endl;
        funcionA(); 
	}
};

int main()
{
	//Se ejecutárán hasta que se llene la pila.
	Comprobar c;
	c.funcionA();
	c.funcionB();
	
	
}





#include <iostream>
#include <vector>

class Calculadora
{
public:
    using tipo_numero = int; // este es un tipo alias anidado

    std::vector<tipo_numero> m_historiaResultado{};

    tipo_numero sumar(tipo_numero a, tipo_numero b)
    {
        auto resultado{ a + b };

        m_historiaResultado.push_back(resultado);

        return resultado;
    }
};

int main()
{
    Calculadora calculadora;

    std::cout << calculadora.sumar(3, 4) << '\n'; // 7
    std::cout << calculadora.sumar(99, 24) << '\n'; // 123

    for (Calculadora::tipo_numero resultado : calculadora.m_historiaResultado)
    {
        std::cout << resultado << '\n';
    }

    return 0;
}




#include <iostream>
#include <vector>

class Calculadora
{
public:
    using tipo_numero = double; // este es un tipo alias anidado

    std::vector<tipo_numero> m_historiaResultado{};

    tipo_numero sumar(tipo_numero a, tipo_numero b)
    {
        auto resultado{ a + b };

        m_historiaResultado.push_back(resultado);

        return resultado;
    }
};

int main()
{
    Calculadora calculadora;

    std::cout << calculadora.sumar(3.3, 4.5) << '\n'; // 7
    std::cout << calculadora.sumar(99.7, 24.2) << '\n'; // 123

    for (Calculadora::tipo_numero resultado : calculadora.m_historiaResultado)
    {
        std::cout << resultado << '\n';
    }

    return 0;
}


#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair

using listapares_t = std::vector<std::pair<std::string, int>>; // hacemos listapares_t un alias 
                                                               //para este tipo enrevesado


#include <string>
#include <array>
#include <vector>
#include <iostream>

int main()
{
    std::string s{ "Hola mundo" }; // instancia un objeto de la clase string
    std::array<int, 3> a{ 1, 2, 3 }; // instancia un objeto de la clase array
    std::vector<double> v{ 1.1, 2.2, 3.3 }; // instancia un objeto de la clase vector

    std::cout << "longitud: " << s.length() << '\n'; // llama a una función miembro
	
	

    return 0;
}



struct StructFecha // miembros son públicos por defecto
{
    int dia{}; // público por defecto, puede acceder cualquiera
    int mes{}; // público por defecto, puede acceder cualquiera
    int anho{}; // público por defecto, puede acceder cualquiera
};

int main()
{
    StructFecha fecha;
    fecha.dia = 10;
    fecha.mes = 03;
    fecha.anho = 2022;

    return 0;
}


class ClaseFecha // miembros son privados por defecto
{
    int m_dia{}; // privado por defecto, solo accesible a otros miembros
    int m_mes{}; // privado por defecto, solo accesible a otros miembros
    int m_anho{};// privado por defecto, solo accesible a otros miembros
};

int main()
{
    ClaseFecha fecha;
    fecha.m_dia = 10; // error
    fecha.m_mes = 03; // error
    fecha.m_anho = 2022; // error

    return 0;
}




 
class ClaseFecha // miembros son privados por defecto
{
    public: // convertirmos los miembros en públicos con "public:"
    int m_dia{}; // privado por defecto, solo accesible a otros miembros
    int m_mes{}; // privado por defecto, solo accesible a otros miembros
    int m_anho{};// privado por defecto, solo accesible a otros miembros
};

int main()
{
    ClaseFecha fecha;
    fecha.m_dia = 10; // correcto
    fecha.m_mes = 03; // correcto
    fecha.m_anho = 2022; // correcto

    return 0;
}
#endif


#include <iostream>

class ClaseFecha // miembros privados por defecto
{
    int m_dia{};  // privado por defecto, solo accesible a otros miembros
    int m_mes{};  // privado por defecto, solo accesible a otros miembros
    int m_anho{}; // privado por defecto, solo accesible a otros miembros

public:
    void setFecha(int dia, int mes, int anho) // público, accesible desde fuera de la Clase
    {
        // setFecha() puede acceder a los miembros de la clase porque también es miembro
        m_dia = dia;
        m_mes = mes;
        m_anho = anho;
    }

    void imprimir() // público, acceso desde fuera de la clase
    {
        std::cout << m_dia << '/' << m_mes << '/' << m_anho;
    }
};

int main()
{
    ClaseFecha fecha;
    fecha.setFecha(10, 03, 2022); // correcto, porque setFecha() es público
    fecha.imprimir(); // correcto, porque imprimir() es público
    std::cout << '\n';

    return 0;
}




#include <iostream>

class ClaseFecha // miembros son privados por defecto
{
    int m_dia{};  // privado por defecto, solo accesible a otros miembros
    int m_mes{};  // privado por defecto, solo accesible a otros miembros
    int m_anho{}; // privado por defecto, solo accesible a otros miembros

public:
    void setFecha(int dia, int mes, int anho) // público, accesible desde fuera de la Clase
    {
        // setFecha() puede acceder a los miembros de la clase porque también es miembro
        m_dia = dia;
        m_mes = mes;
        m_anho = anho;
    }

    void imprimir() // público, acceso desde fuera de la clase
    {
        std::cout << m_dia << '/' << m_mes << '/' << m_anho;
    }

    // Añadimos esta nueva función
    void copiarDe(const ClaseFecha& d)
    {
        // Observa que podemos acceder a los miembros privados de d directamente
        m_dia = d.m_dia;
        m_mes = d.m_mes;
        m_anho = d.m_anho;
    }
};

int main()
{
    ClaseFecha fecha;
    fecha.setFecha(10, 03, 2022); // correcto, porque setFecha() es público

    ClaseFecha copiar{};
    copiar.copiarDe(fecha); // correcto, porque copiarDe() es público
    copiar.imprimir();
    std::cout << '\n';

    return 0;
}

#if 0 
#endif