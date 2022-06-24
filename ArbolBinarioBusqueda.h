#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class motorizado{
	public:
		string nombre,apellido,edad,dni;
		string dia,mes,anio;
		string direccion;
		string cod_motorizado,nro_placa,marcaMoto;
};

struct node{
  	motorizado M;
	node *left, *right;
};

node *newNode(motorizado m){
  	node *temp =new node();
  	temp->M=m;
  	temp->left=temp->right=NULL;
  	return temp;
}


// Insert a node
struct node *insertar(struct node *node,motorizado m){
  	if(node==NULL) return newNode(m);
	if(m.nombre<node->M.nombre) node->left=insertar(node->left,m);
  	else node->right=insertar(node->right,m);
	return node;
}

void inorder(node *root){
  	if(root!=NULL){
    	inorder(root->left);
    	cout<<"Nombre            : "<<root->M.nombre<<endl;
    	cout<<"Apellidos         : "<<root->M.apellido<<endl;
    	cout<<"Edad              : "<<root->M.edad<<endl;
    	cout<<"DNI               : "<<root->M.dni<<endl;
    	cout<<"Fecha Nacimiento  : "<<root->M.dia<<"/"<<root->M.mes<<"/"<<root->M.anio<<endl;
    	cout<<"Direccion         : "<<root->M.direccion<<endl;
		cout<<"Codigo Motorizado : "<<root->M.cod_motorizado<<endl;
		cout<<"Numero de placa   : "<<root->M.nro_placa<<endl;
		cout<<"Marca De Moto     : "<<root->M.marcaMoto<<endl; 
		cout<<endl;
		inorder(root->right);
  	}
}

void buscarMotorizado(node *root,string nombre){
	node *temp=new node();
	temp=root;
	while(temp!=NULL){
		if(temp->M.nombre==nombre){
			cout<<"Nombre            : "<<temp->M.nombre<<endl;
 		   	cout<<"Apellidos         : "<<temp->M.apellido<<endl;
    		cout<<"Edad              : "<<temp->M.edad<<endl;
    		cout<<"DNI               : "<<temp->M.dni<<endl;
    		cout<<"Fecha Nacimiento  : "<<temp->M.dia<<"/"<<root->M.mes<<"/"<<root->M.anio<<endl;
    		cout<<"Direccion         : "<<temp->M.direccion<<endl;
			cout<<"Codigo Motorizado : "<<temp->M.cod_motorizado<<endl;
			cout<<"Numero de placa   : "<<temp->M.nro_placa<<endl;
			cout<<"Marca De Moto     : "<<temp->M.marcaMoto<<endl; 
			return;
		}
		else if(temp->M.nombre>nombre) temp=temp->left;
		else temp=temp->right;
	}
 	cout<<endl;
 	cout<<"  > NO SE ENCONTRO MOTORIZADO CON ESE NOMBRE <"<<endl;
	return;
}

node *leerArchivo(){
	node *root=NULL;
	
	ifstream archivo("motorizados.txt");
	string linea;
	
	motorizado t;
	
	while(getline(archivo,linea)){
		stringstream stream(linea);
		
		getline(stream,t.nombre,',');
		getline(stream,t.apellido,',');
		getline(stream,t.edad,',');
		getline(stream,t.dni,',');
		getline(stream,t.dia,',');
		getline(stream,t.mes,',');
		getline(stream,t.anio,',');
		getline(stream,t.direccion,',');	
		getline(stream,t.cod_motorizado,',');
		getline(stream,t.nro_placa,',');
		getline(stream,t.marcaMoto,',');
		
		root=insertar(root,t);
	}
	
	return root;
}

