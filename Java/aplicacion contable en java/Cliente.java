public class Cliente { // Definicion de la clase Cliente
    private String nombre;     // Variable para almacenar el nombre del cliente
    private String apellido;   // Variable para almacenar el apellido del cliente
    private String direccion;  // Variable para almacenar la direccion del cliente
    private String telefono;   // Variable para almacenar el telefono del cliente
    private String correo;     // Variable para almacenar el correo electronico del cliente
    private String nit;        // Variable para almacenar el numero de identificacion tributaria
    
    // Constructor de la clase Cliente que recibe todos los parametros
    public Cliente(String nombre, String apellido, String direccion, String telefono, String correo, String nit) 
    {
        this.nombre = nombre;         // Asigna el nombre recibido al atributo de la clase
        this.apellido = apellido;     // Asigna el apellido recibido al atributo de la clase
        this.direccion = direccion;   // Asigna la direccion recibida al atributo de la clase
        this.telefono = telefono;     // Asigna el telefono recibido al atributo de la clase
        this.correo = correo;         // Asigna el correo recibido al atributo de la clase
        this.nit = nit;               // Asigna el nit recibido al atributo de la clase
    }

    public String getNombre() {    // Metodo para obtener el nombre del cliente
        return nombre;            // Retorna el valor del nombre
    }

    public String getApellido() {  // Metodo para obtener el apellido del cliente
        return apellido;          // Retorna el valor del apellido
    }

    public String getDireccion() { // Metodo para obtener la direccion del cliente
        return direccion;         // Retorna el valor de la direccion
    }

    public String getTelefono() {  // Metodo para obtener el telefono del cliente
        return telefono;          // Retorna el valor del telefono
    }

    public String getCorreo() {    // Metodo para obtener el correo del cliente
        return correo;            // Retorna el valor del correo
    }

    public String getNit() {       // Metodo para obtener el nit del cliente
        return nit;               // Retorna el valor del nit
    }
}