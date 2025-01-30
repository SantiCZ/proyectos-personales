package com.reservas.vuelos.service;

import java.util.ArrayList;
import java.util.List;

public class ReservaService {
    private List<Reserva> reservas = new ArrayList<>();

    public Reserva reservarVuelo(Usuario usuario, Vuelo vuelo, String fechaReserva) {
        if (vuelo.getAsientosDisponibles() > 0) {
            vuelo.setAsientosDisponibles(vuelo.getAsientosDisponibles() - 1);
            Reserva reserva = new Reserva(reservas.size() + 1, usuario, vuelo, fechaReserva);
            reservas.add(reserva);
            return reserva;
        }
        return null;
    }

    public boolean cancelarReserva(int idReserva) {
        Reserva reserva = reservas.stream()
                .filter(r -> r.getId() == idReserva)
                .findFirst()
                .orElse(null);
        if (reserva != null) {
            try {
                ((Vuelo) reserva.getVuelo()).setAsientosDisponibles(((Vuelo) reserva.getVuelo()).getAsientosDisponibles() + 1);
            } catch (Exception e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            reservas.remove(reserva);
            return true;
        }
        return false;
    }
}