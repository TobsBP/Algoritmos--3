bool bfs_poder_acumulado(Habilidade adj[], int vertices, int start, float poder_acumulado[]){
	
	bool visited[vertices];
	list<int> to_visit_queue;
	
	for(int i=0;i<vertices;i++){
		visited[i] = false;
	}
	
	visited[start] = true;
	to_visit_queue.push_back(start);
	
	while(!to_visit_queue.empty()){
		int curr = to_visit_queue.front();
		to_visit_queue.pop_front();
		list<no>::iterator p;
		for(p=adj[curr].upgrades.begin();p!=adj[curr].upgrades.end();p++){
			int dest = p->dest;
			if(!visited[dest]){
				visited[dest] = true;
				to_visit_queue.push_back(dest);
				poder_acumulado[dest] += poder_acumulado[curr];
			}				
		}
			
	}
	return true;	
}

void shortest_path_dijkstra(Habilidade adj[], float poder_acumulado[], int vertices, int start)
{
  bool intree[vertices];
  int distance[vertices], parent[vertices];

  for (int u = 0; u < vertices; u++)
  {
    intree[u] = false;
    distance[u] = INT_MAX;
    parent[u] = -1;
  }
  distance[start] = 0;
  int v = start;
  while (intree[v] == false)
  {
    intree[v] = true;
    list<no>::iterator p;
    for (p = adj[v].upgrades.begin(); p != adj[v].upgrades.end(); p++)
    {
      int dest = p->dest;
      int weight = p->custo;
      if (distance[dest] > distance[v] + weight)
      {
        distance[dest] = distance[v] + weight;
        parent[dest] = v;
      }
    }
    v = 0;
    int dist = INT_MAX, poder = 0;
    for (int u = 0; u < vertices; u++)
    {
      if (intree[u] == false && distance[u] < dist)
      {
        dist = distance[u];
        v = u;
      }
    }
  }
  int dist = INT_MAX;
  for (int u = 0; u < vertices; u++)
  {
    if (intree[u] == true && distance[u] < dist)
    {
      dist = distance[u];
    }
  }
  
  cout << dist << endl;
}