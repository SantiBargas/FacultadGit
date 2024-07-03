package ParcialObjetos;

import java.util.Calendar;
import java.util.Vector;

public class RolComensalDTO extends RolUsuarioDTO{

	private Calendar ultimoAcceso;
	private String tokenSesion;
	private Facultad myFacultad;
	private Vector<Cupon>myCupones;
	
	public RolComensalDTO(UsuarioDTO myUsuario, Calendar ultimoAcceso, String tokenSesion, Facultad myFacultad,
			Vector<Cupon> myCupones) {
		super(myUsuario);
		this.ultimoAcceso = ultimoAcceso;
		this.tokenSesion = tokenSesion;
		this.myFacultad = myFacultad;
		this.myCupones = new Vector<Cupon>();
	}

	@Override
	public boolean esComensal() {
		return true;
	}
	
	public void MostrarSaldo() {
		System.out.println("El saldo es"+this.CalcularSaldo());
	}
	
	public Integer CalcularSaldo() {
		Integer saldo = 0;
		for(Cupon oCupon : myCupones) {
			if(oCupon.disponible()==true) {
				saldo++;
			}
		}
		return saldo;
	}

	public void mostrarFacultadComensal() {
		this.myFacultad.mostrar();
		
	}

	
	
}
