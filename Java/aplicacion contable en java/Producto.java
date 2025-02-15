// Clase que representa un producto
public class Producto {
    // Variable para almacenar el nombre del producto
    private String nombre;
    // Variable para almacenar el precio del producto
    private double precio;
    // Variable para almacenar la cantidad del producto
    private int cantidad;
    
    // Constructor de la clase Producto
    public Producto(String nombre, double precio, int cantidad) {
        // Asigna el nombre recibido al atributo nombre
        this.nombre = nombre;
        // Asigna el precio recibido al atributo precio
        this.precio = precio;
        // Asigna la cantidad recibida al atributo cantidad
        this.cantidad = cantidad;
    }
    
    // Metodo para obtener el nombre del producto
    public String getNombre() {
        // Retorna el nombre del producto
        return nombre;
    }
    
    // Metodo para establecer el nombre del producto
    public void setNombre(String nombre) {
        // Asigna el nuevo nombre al producto
        this.nombre = nombre;
    }
    
    // Metodo para obtener el precio del producto
    public double getPrecio() {
        // Retorna el precio del producto
        return precio;}
    
    // Metodo para establecer el precio del producto
    public void setPrecio(double precio) {
        // Asigna el nuevo precio al producto
        this.precio = precio;
    }
    
    // Metodo para obtener la cantidad del producto
    public int getCantidad() {
        // Retorna la cantidad del producto
        return cantidad;
    }
    
    // Metodo para establecer la cantidad del producto
    public void setCantidad(int cantidad) {
        // Asigna la nueva cantidad al producto
        this.cantidad = cantidad;
    }
}
