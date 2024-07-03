package ParcialObjetos;

import java.util.Vector;

public class Universidad {

	private Vector<UsuarioDTO>myUsuarioDTO;
	private Vector<Facultad>myFacultad;
	private Vector<ComedorDTO>myComedorDTO;
	private String nombre;
	
	public Universidad(String nombre) {
		super();
		this.myUsuarioDTO = new Vector<UsuarioDTO>();
		this.myFacultad = new Vector<Facultad>();
		this.myComedorDTO =new Vector<ComedorDTO>();
		this.nombre = nombre;
	}
	
	public void ListarUsuarios() {
		//Listar los usuarios que tengan mas de un rol
		//y a su vez sean comensales
		
		for(UsuarioDTO oUsuario : myUsuarioDTO) {
			if(oUsuario.masDeUnRol()==true && 
					oUsuario.esComensal()==true) {
				oUsuario.mostrarNombre();
				oUsuario.mostrarFacultad();
				oUsuario.mostrarSaldo();
			}
				
		}
	}

	public void addUsuario(UsuarioDTO aUsuarioDTO) {
		myUsuarioDTO.add(aUsuarioDTO);
		
	}
	
	public void addFacultad(Facultad Facultad) {
		myFacultad.add(Facultad);
		
	}
	
}
