import java.util.Scanner; 
public class UnitConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n=== Conversor de Unidades ===");
            System.out.println("1. Longitud");
            System.out.println("2. Peso");
            System.out.println("3. Temperatura");
            System.out.println("4. Salir");
            System.out.print("Elige una opción: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    convertLength(scanner);
                    break;
                case 2:
                    convertWeight(scanner);
                    break;
                case 3:
                    convertTemperature(scanner);
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opción no válida. Inténtalo de nuevo.");
            }
        } while (choice != 4);

        scanner.close();
    }
    private static void convertLength(Scanner scanner) {
        System.out.println("\nConversión de Longitud:");
        System.out.println("1. Metros a Kilómetros");
        System.out.println("2. Kilómetros a Millas");
        System.out.println("3. Millas a Metros");
        System.out.print("Elige una opción: ");
        int choice = scanner.nextInt();
        System.out.print("Introduce el valor: ");
        double value = scanner.nextDouble();
        double result;
        switch (choice) {
            case 1:
                result = value / 1000;
                System.out.printf("%.2f metros son %.2f kilómetros.\n", value, result);
                break;
            case 2:
                result = value * 0.621371;
                System.out.printf("%.2f kilómetros son %.2f millas.\n", value, result);
                break;
            case 3:
                result = value * 1609.34;
                System.out.printf("%.2f millas son %.2f metros.\n", value, result);
                break;
            default:
                System.out.println("Opción no válida.");
        }
    }
    private static void convertWeight(Scanner scanner) {
        System.out.println("\nConversión de Peso:");
        System.out.println("1. Kilogramos a Libras");
        System.out.println("2. Libras a Kilogramos");
        System.out.print("Elige una opción: ");
        int choice = scanner.nextInt();
        System.out.print("Introduce el valor: ");
        double value = scanner.nextDouble();
        double result;
        switch (choice) {
            case 1:
                result = value * 2.20462;
                System.out.printf("%.2f kilogramos son %.2f libras.\n", value, result);
                break;
            case 2:
                result = value / 2.20462;
                System.out.printf("%.2f libras son %.2f kilogramos.\n", value, result);
                break;
            default:
                System.out.println("Opción no válida.");
        }
    }
    private static void convertTemperature(Scanner scanner) {
        System.out.println("\nConversión de Temperatura:");
        System.out.println("1. Celsius a Fahrenheit");
        System.out.println("2. Fahrenheit a Celsius");
        System.out.print("Elige una opción: ");
        int choice = scanner.nextInt();
        System.out.print("Introduce el valor: ");
        double value = scanner.nextDouble();
        double result;
        switch (choice) {
            case 1:
                result = (value * 9/5) + 32;
                System.out.printf("%.2f grados Celsius son %.2f grados Fahrenheit.\n", value, result);
                break;
            case 2:
                result = (value - 32) * 5/9;
                System.out.printf("%.2f grados Fahrenheit son %.2f grados Celsius.\n", value, result);
                break;
            default:
                System.out.println("Opción no válida.");
        }
    }
}
