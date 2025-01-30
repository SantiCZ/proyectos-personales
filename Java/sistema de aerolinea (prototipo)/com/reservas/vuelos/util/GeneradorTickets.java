package com.reservas.vuelos.util;

import utilidades.Ticket;

public class GeneradorTickets {
    public static Ticket generarTicket(utilidades.Reserva reserva) {
        String codigoTicket = "TICKET-" + reserva.getId() + "-" + reserva.getVuelo().getId();
        return new Ticket(reserva.getId(), reserva, codigoTicket);
    }
}
