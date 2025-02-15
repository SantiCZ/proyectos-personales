//apliacion contable en Java
//importacion de la clase Scanner para entrada de datos
import java.util.Scanner;
//definicion de la clase principal
public class Main {
    //metodo principal que ejecuta el programa
    static void main(String[] args) {
        //creacion de objeto Scanner para entrada de datos
        try (Scanner scanner = new Scanner(System.in)) {
            //mensaje de bienvenida
            System.out.println("Bienvenido, ingrese lo que desee hacer: ");
            //opciones del menu
            System.out.println("1. Ingresar un nuevo cliente");
            System.out.println("2. Ingresar un nuevo producto");
            System.out.println("3. Ingresar una nueva factura");
            System.out.println("4. consultar un cliente");
            System.out.println("5. consultar un producto");
            System.out.println("6. consultar una factura");
            System.out.println("7. ver libros contables");
            System.out.println("8. ver estado de cuenta de un cliente");
            System.out.println("9. ver estado de deuda de un cliente");
            System.out.println("10. ver planilla de datos de un cliente");
            System.out.println("11. ver planilla de datos de un producto");
            System.out.println("12. ver planilla de datos de una factura");
            System.out.println("13. ver planilla de datos de un libro contable");
            System.out.println("14. ver planilla de datos de un estado de cuenta");
            System.out.println("15. Salir");
            
            //lectura de la opcion seleccionada
            int opcion = scanner.nextInt();
            //limpieza del buffer de entrada
            scanner.nextLine();
            
            //estructura switch para manejar las opciones
            switch (opcion) {
                case 1:
                    //captura de datos del cliente
                    System.out.println("Ingrese el nombre del cliente: ");
                    String nombreCliente = scanner.nextLine();
                    System.out.println("Ingrese el apellido del cliente: ");
                    String apellido = scanner.nextLine();
                    System.out.println("Ingrese la direccion del cliente: ");
                    String direccion = scanner.nextLine();
                    System.out.println("Ingrese el telefono del cliente: ");
                    String telefono = scanner.nextLine();
                    System.out.println("Ingrese el correo del cliente: ");
                    String correo = scanner.nextLine();
                    System.out.println("Ingrese el nit del cliente: ");
                    String nit = scanner.nextLine();
                    //creacion del objeto cliente
                    Cliente cliente = new Cliente(nombreCliente, apellido, direccion, telefono, correo, nit);
                    //mensaje de confirmacion
                    System.out.println("Cliente creado: " + cliente);
                    break;
                case 2:
                    //captura de datos del producto
                    System.out.println("Ingrese el nombre del producto: ");
                    String nombreProducto = scanner.nextLine();
                    System.out.println("Ingrese el precio del producto: ");
                    double precio = scanner.nextDouble();
                    System.out.println("Ingrese la cantidad del producto: ");
                    int cantidad = scanner.nextInt();
                    //creacion del objeto producto
                    Producto producto = new Producto(nombreProducto, precio, cantidad);
                    //mensaje de confirmacion
                    System.out.println("Producto creado: " + producto);
                    break;
                case 3:
                    //captura de datos para la factura
                    System.out.println("Ingrese el nombre del cliente: ");
                    String nombreClienteFactura = scanner.nextLine();
                    System.out.println("Ingrese el apellido del cliente: ");
                    String apellidoFactura = scanner.nextLine();
                    System.out.println("Ingrese la direccion del cliente: ");
                    String direccionFactura = scanner.nextLine();
                    System.out.println("Ingrese el telefono del cliente: ");
                    String telefonoFactura = scanner.nextLine();
                    System.out.println("Ingrese el correo del cliente: ");
                    String correoFactura = scanner.nextLine();
                    System.out.println("Ingrese el nit del cliente: ");
                    String nitFactura = scanner.nextLine();
                    //creacion del objeto cliente para la factura
                    Cliente clienteFactura = new Cliente(nombreClienteFactura, apellidoFactura, direccionFactura, telefonoFactura, correoFactura, nitFactura);
                    //captura de datos del producto para la factura
                    System.out.println("Ingrese el nombre del producto: ");
                    String nombreProductoFactura = scanner.nextLine();
                    System.out.println("Ingrese el precio del producto: ");
                    double precioFactura = scanner.nextDouble();
                    System.out.println("Ingrese la cantidad del producto: ");
                    int cantidadFactura = scanner.nextInt();
                    //creacion del objeto producto para la factura
                    Producto productoFactura = new Producto(nombreProductoFactura, precioFactura, cantidadFactura);
                    //captura de datos adicionales de la factura
                    System.out.println("Ingrese el numero de factura: ");
                    int numero = scanner.nextInt();
                    System.out.println("Ingrese la fecha de la factura: ");
                    String fecha = scanner.nextLine();
                    System.out.println("Ingrese el total de la factura: ");
                    double total = scanner.nextDouble();
                    //creacion del objeto factura
                    Factura factura = new Factura(numero, fecha, total, clienteFactura, productoFactura);
                    //mensaje de confirmacion
                    System.out.println("Factura creada: " + factura);
                    break;
                default:
                    //mensaje para opcion invalida
                    System.out.println("Opción no válida");
                    break;
            }
        }
    }
}
