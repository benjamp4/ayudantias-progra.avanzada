void recorrerQueue(queue<int> cola){
    while(!cola.empty()){
        cout << cola.front() << endl;
        cola.pop();
    }
} // Esto eliminará la copia de la cola, la original no se cambia


// Se recomienda recorrerla de esta forma...
queue<int> cola; // Tenemos una cola
queue<int> temporal = cola; // Creamos una nueva cola temporal, que es una copia de la otra

void recorrerQueue(queue<int> temporal){
    while(!temporal.empty()){ 
        cout << temporal.front() << endl;
        temporal.pop();
    }
}


