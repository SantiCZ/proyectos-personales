import java.util.ArrayList;
import java.util.List;
// Clase para representar un ingreso
class Ingreso {
    String descripcion;  // Descripcion del ingreso
    double monto;        // Monto del ingreso
    // Constructor que inicializa la descripcion y el monto
    public Ingreso(String descripcion, double monto) {
        this.descripcion = descripcion;
        this.monto = monto;
    }
    // Metodo toString para mostrar el ingreso
    @Override
    public String toString() {
        return descripcion + ": " + monto;
    }
}
// Clase para representar un gasto
class Gasto {
    String descripcion;  // Descripcion del gasto
    double monto;        // Monto del gasto
    // Constructor que inicializa la descripcion y el monto
    public Gasto(String descripcion, double monto) {
        this.descripcion = descripcion;
        this.monto = monto;
    }
    // Metodo toString para mostrar el gasto
    @Override
    public String toString() {
        return descripcion + ": " + monto;
    }
}
// Clase para generar el reporte financiero
class Reporte {
    List<Ingreso> ingresos;  // Lista de ingresos
    List<Gasto> gastos;      // Lista de gastos
    // Constructor que inicializa las listas de ingresos y gastos
    public Reporte() {
        ingresos = new ArrayList<>();
        gastos = new ArrayList<>();
    }
    // Metodo para agregar un ingreso al reporte
    public void agregarIngreso(Ingreso ingreso) {
        ingresos.add(ingreso);
    }
    // Metodo para agregar un gasto al reporte
    public void agregarGasto(Gasto gasto) {
        gastos.add(gasto);
    }
    // Metodo para calcular el total de los ingresos
    public double calcularTotalIngresos() {
        double total = 0;
        // Se recorre la lista de ingresos y se suma cada monto
        for (Ingreso ingreso : ingresos) {
            total += ingreso.monto;
        }
        return total;
    }
    // Metodo para calcular el total de los gastos
    public double calcularTotalGastos() {
        double total = 0;
        // Se recorre la lista de gastos y se suma cada monto
        for (Gasto gasto : gastos) {
            total += gasto.monto;
        }
        return total;
    }
    // Metodo para calcular el balance final (ingresos - gastos)
    public double calcularBalance() {
        return calcularTotalIngresos() - calcularTotalGastos();
    }
    // Metodo para generar y mostrar el reporte completo
    public void generarReporte() {
        System.out.println("Reporte de Finanzas del Mes:");
        System.out.println("Ingresos:");
        // Se imprime cada ingreso
        for (Ingreso ingreso : ingresos) {
            System.out.println(ingreso);
        }
        System.out.println("Gastos:");
        // Se imprime cada gasto
        for (Gasto gasto : gastos) {
            System.out.println(gasto);
        }
        // Se muestran los totales de ingresos, gastos y el balance final
        System.out.println("Total Ingresos: " + calcularTotalIngresos());
        System.out.println("Total Gastos: " + calcularTotalGastos());
        System.out.println("Balance Final: " + calcularBalance());
    }
}
// Clase principal que ejecuta el simulador financiero
public class SimuladorFinanciero {
    public static void main(String[] args) {
        // Crear un reporte financiero
        Reporte reporte = new Reporte();
        // Agregar algunos ingresos
        reporte.agregarIngreso(new Ingreso("Salario", 2500));
        reporte.agregarIngreso(new Ingreso("Venta productos", 800));
        // Agregar algunos gastos
        reporte.agregarGasto(new Gasto("Alquiler", 800));
        reporte.agregarGasto(new Gasto("Comida", 400));
        reporte.agregarGasto(new Gasto("Transporte", 150));
        // Generar y mostrar el reporte
        reporte.generarReporte();
    }
}
