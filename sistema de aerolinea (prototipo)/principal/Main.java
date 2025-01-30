package principal;

import com.reservas.vuelos.service.*;
import com.reservas.vuelos.service.Vuelo;
import com.reservas.vuelos.util.GeneradorTickets;

import utilidades.Ticket;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Crear algunos vuelos
        Vuelo vuelo1 = new Vuelo(1, "Madrid", "Barcelona", "2023-10-01", 100);
        Vuelo vuelo2 = new Vuelo(2, "Barcelona", "Valencia", "2023-10-02", 50);

        List<Vuelo> vuelos = List.of(vuelo1, vuelo2);

        // Crear servicios
        VueloService vueloService = new VueloService(vuelos);
        UsuarioService usuarioService = new UsuarioService();
        ReservaService reservaService = new ReservaService();

        // Registrar un usuario
        Usuario usuario = new Usuario(1, "Juan Perez", "juan@example.com");
        usuarioService.registrarUsuario(usuario);

        // Buscar vuelos
        List<Vuelo> vuelosDisponibles = vueloService.buscarVuelos("Madrid", "Barcelona", "2023-10-01");
        System.out.println("Vuelos disponibles: " + vuelosDisponibles.size());

        // Reservar un vuelo
        Reserva reserva = reservaService.reservarVuelo(usuario, vuelo1, "2023-09-25");
        if (reserva != null) {
            System.out.println("Reserva realizada con éxito.");

            // Generar ticket
            Ticket ticket = GeneradorTickets.generarTicket(new utilidades.Reserva(reserva.getId(), reserva.getUsuario(), reserva.getVuelo(), reserva.getFechaReserva()));
            System.out.println("Ticket generado: " + ticket.getCodigo());
        }

        // Cancelar reserva
        boolean cancelado = reservaService.cancelarReserva(reserva.getId());
        if (cancelado) {
            System.out.println("Reserva cancelada con éxito.");
        }
    }
}

