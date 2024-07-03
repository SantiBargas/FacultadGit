package ParcialObjetos;

import java.util.Vector;

public class UsuarioDTO {

	private String usuario;
	private String apellido;
	private String nombre;
	private String correo;
	private Vector<RolUsuarioDTO>myRolUsuarioDTO;
	
	public UsuarioDTO(String usuario, String apellido, String nombre, String correo) {
		super();
		this.usuario = usuario;
		this.apellido = apellido;
		this.nombre = nombre;
		this.correo = correo;
		this.myRolUsuarioDTO=new Vector<RolUsuarioDTO>();
	}

	public void addRol(RolUsuarioDTO rolUsuarioDTO) {
		myRolUsuarioDTO.add(rolUsuarioDTO);
		
	}

	public boolean masDeUnRol() {
		Integer cont = this.getCantRoles();
		boolean respuesta = false;
		if( cont >=2) {respuesta = true;}
		return respuesta;
	}

	private Integer getCantRoles() {
		Integer cont = 0;
		for(RolUsuarioDTO oRol : myRolUsuarioDTO) {
			cont++;
		}
		return cont;
	}

	public boolean esComensal() {
		for(RolUsuarioDTO oRol : myRolUsuarioDTO) { //Con que uno de sus N roles sea comensal ya me alcanza para decir que es verdadero
			if (oRol.esComensal()==true) {
				return true;
			}
		}
		return false;
	}

	public void mostrarNombre() {
		System.out.println("Nombre: "+this.nombre+ "\n " + "Apellido:" + this.apellido);
		
	}

	public void mostrarFacultad() {
		for(RolUsuarioDTO oRol : myRolUsuarioDTO) {
			oRol.mostrarFacultad();
		}
	}

	public void mostrarSaldo() {
		for(RolUsuarioDTO oRol : myRolUsuarioDTO) {
			oRol.mostrarSaldo();
		}
	}
	
	
	
}
