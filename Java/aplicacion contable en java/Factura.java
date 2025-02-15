// Clase que representa una factura
public class Factura {
    // Numero de factura
    private int numero;
    // Fecha de emision de la factura
    private String fecha;
    // Constructor de la factura que recibe parametros basicos
    public Factura(int numero, String fecha, double total2, Cliente clienteFactura, Producto productoFactura) {
        // Asigna el numero de factura
        this.numero = numero;
        // Asigna la fecha de factura
        this.fecha = fecha;
        // Asigna el total de la factura
        this.total = total2;
    }
    // Metodo para obtener el numero de factura
    public int getNumero() {
        return numero;
    }
    // Metodo para obtener la fecha de factura
    public String getFecha() {
        return fecha;
    }
    // Nombre del cliente o producto
    private String nombre;
    // Total de la factura sin calculos
    private double total;
    // Valor del IVA
    private double iva;
    // Subtotal antes de impuestos
    private double subtotal;
    // Porcentaje de descuento
    private double descuento;
    // Total del descuento aplicado
    private double totalDescuento;
    // Total del IVA calculado
    private double totalIva;
    // Total final de la factura
    private double totalFactura;
    // Total con descuento e IVA aplicados
    private double totalDescuentoIva;

    // Obtiene el nombre
    public String getNombre() { return nombre; }
    // Establece el nombre
    public void setNombre(String nombre) { this.nombre = nombre; }
    // Obtiene el total
    public double getTotal() { return total; }
    // Establece el total
    public void setTotal(double total) { this.total = total; }
    // Obtiene el IVA
    public double getIva() { return iva; }
    // Establece el IVA
    public void setIva(double iva) { this.iva = iva; }
    // Obtiene el subtotal
    public double getSubtotal() { return subtotal; }
    // Establece el subtotal
    public void setSubtotal(double subtotal) { this.subtotal = subtotal; }
    // Obtiene el descuento
    public double getDescuento() { return descuento; }
    // Establece el descuento
    public void setDescuento(double descuento) { this.descuento = descuento; }
    // Obtiene el total del descuento
    public double getTotalDescuento() { return totalDescuento; }
    // Establece el total del descuento
    public void setTotalDescuento(double totalDescuento) { this.totalDescuento = totalDescuento; }
    // Obtiene el total del IVA
    public double getTotalIva() { return totalIva; }
    // Establece el total del IVA
    public void setTotalIva(double totalIva) { this.totalIva = totalIva; }
    // Obtiene el total de la factura
    public double getTotalFactura() { return totalFactura; }
    // Establece el total de la factura
    public void setTotalFactura(double totalFactura) { this.totalFactura = totalFactura; }
    // Obtiene el total con descuento e IVA
    public double getTotalDescuentoIva() { return totalDescuentoIva; }
    // Establece el total con descuento e IVA
    public void setTotalDescuentoIva(double totalDescuentoIva) { this.totalDescuentoIva = totalDescuentoIva; }
}
