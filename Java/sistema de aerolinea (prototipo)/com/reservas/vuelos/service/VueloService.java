package com.reservas.vuelos.service;

import java.util.List;

public class VueloService {
    private List<Vuelo> vuelos;

    public VueloService(List<Vuelo> vuelos2) {
        this.vuelos = vuelos2;
    }

    public List<Vuelo> buscarVuelos(String origen, String destino, String fecha) {
        return vuelos.stream()
                .filter(v -> v.getOrigen().equals(origen) && 
                             v.getDestino().equals(destino) && 
                             v.getFecha().equals(fecha))
                .toList();
    }
}