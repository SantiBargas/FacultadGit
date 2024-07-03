package ParcialObjetos;

import java.util.Calendar;

public class Cupon {

	private String identificador; 
	private Calendar fechacompra;
	private Entrega myEntrega;
	
	public Cupon(String identificador, Calendar fechacompra, Entrega myEntrega) {
		super();
		this.identificador = identificador;
		this.fechacompra = fechacompra;
		this.myEntrega = myEntrega;
	}
	
	//Si entrega es null, el cupon no fue entregado y esta a nuestra disposicion
    //contaria como saldo
	
	public void addEntrega(Entrega entrega) {
		this.myEntrega=entrega;
		
	}

	public boolean disponible() {
		
		boolean respuesta = false;
		
		if(this.myEntrega!=null) {
			respuesta = true;
		}
		return respuesta;
	}

}
