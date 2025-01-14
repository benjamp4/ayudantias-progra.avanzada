#include <iostream>
#include <queue>
using namespace std;

class ManejoListaDeEspera
{
	private:
		queue<string> urgencia, normal;
		int cont_urgencias;
	public:
		ManejoListaDeEspera(){
			cont_urgencias = 0;
		}
		
		void anadirPaciente(string nombre, int criticidad){
			if (criticidad == 1){
				urgencia.push(nombre);
			} else {
				normal.push(nombre);
			}
		}
		
		string llamarPaciente(){
			string rr = "";
			if (!urgencia.empty() && cont_urgencias < 5){
				rr = urgencia.front();
				urgencia.pop();
				cont_urgencias++;
			}
			else if (!normal.empty()){
				rr = normal.front();
				normal.pop();
				cont_urgencias = 0;
			}
			return rr;
		}
		
		void estadisticaEspera(){
			cout << "pacientes..." << endl;
			cout << "en total: " << urgencia.size()  + normal.size() << endl;
			cout << "en urgencia: " << urgencia.size() << endl;
			cout << "normal: " << normal.size() << endl;
		}
};

int main(){
	return 0;
}
