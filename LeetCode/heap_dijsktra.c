#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge
{
	int u;
	int v;
	int len;
	struct Edge *next;
} Edge;

typedef struct Vertex
{
	int index;
	int distance;
	Edge *edges;
} Vertex;

typedef struct HeapElement
{
	int v;
	int d;
} HeapElement;

#define INF 2147483647

int N;
Edge** links;

void init_graph(int n)
{
	N = n;
	links = (Edge**)calloc(N, sizeof(Edge*));
}

void add_edge(int u, int v, int len)
{
	Edge* e = (Edge*)malloc(sizeof(Edge));

	e->u = u;e->v = v;e->len = len;
	e->next = links[u];
	links[u] = e;
}

int heap_size;
HeapElement* heap;
int* heap_index;

void init_heap(int n)
{
	heap_size = n;
	heap = (HeapElement*)malloc(sizeof(HeapElement)*n);
	heap_index = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; ++i)
	{
		heap[i].v = i;
		heap[i].d = INF;
		heap_index[i] = i;
	}
}

void heap_swap(int i, int j)
{
	HeapElement t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;

	heap_index[heap[i].v] = i;
	heap_index[heap[j].v] = j;
}

void heap_up(int i)
{
	while (i > 0)
	{
		int j = (i - 1) / 2;
		if (heap[i].d < heap[j].d)
		{
			heap_swap(i, j);
			i = j;
		}
		else
			break;
	}
}

void heap_down(int i)
{
	while (i * 2 + 1 < heap_size)
	{
		int j = i * 2 + 1;
		if (j + 1 < heap_size && heap[j+1].d < heap[j].d) ++j;

		if (heap[j].d < heap[i].d)
		{
			heap_swap(i, j);
		}
		else
			break;
		i = j;
	}
}

void heap_pop()
{
	heap_swap(0, heap_size - 1);
	--heap_size;
	heap_down(0);
}

void dijsktra(int source)
{
	Edge* e;
	if (source<0 || source >= N) return;
	init_heap(N);
	heap[source].d = 0;
	heap_up(source);

	for (int i = 0; i < N; ++i)
	{
		int v = heap[0].v;
		int dist = heap[0].d;
		heap_pop();

		printf("Turn:%d %d %d\n",i,v,dist);

		for (e = links[v]; e != NULL; e = e->next)
		{
			int hi = heap_index[e->v];
			if (hi < heap_size && dist + e->len < heap[hi].d)
			{
				heap[hi].d = dist + e->len;

				printf("%d %d %d|",e->v, heap[hi].v,heap[hi].d);
				heap_up(hi);
			}
		}
		printf("\n");
	}
}



void release_resources()
{
	for (int i = 0; i < N; ++i)
	{
		Edge* p = links[i];
		while (p != NULL)
		{
			Edge* q = p;
			p = p->next;
			free(q);
		}
	}
	if (links!=NULL) free(links);
	if (heap!=NULL) free(heap);
	if (heap_index!=NULL) free(heap_index);
}

int main3214324()
{
	int n, m;
	int most_dist = 0, most_vertex = 0;

	scanf("%d %d",&n,&m);
	init_graph(n);

	for (int i = 0; i < m; ++i)
	{
		int u, v, len;
		scanf("%d %d %d",&u,&v,&len);
		add_edge(u, v, len);
		add_edge(v, u, len);
	}

	dijsktra(0);

	for (int i = 0; i < N; ++i)
	{
		int j = heap_index[i];

		if (heap[j].d!=INF && heap[j].d > most_dist)
		{
			most_dist = heap[j].d;
			most_vertex = heap[j].v;
		}
	}

	printf("most distant vertex %d, distance %d", most_vertex, most_dist);

	release_resources();
	system("pause");
	return 0;
}