#include "LinkedList.h"

/*--------------------------------NODE--------------------------------*/

/**
 * @fn Node getNode*(LinkedList*, int)
 * @brief obtiene el nodo correspondiente a la posicion especificada por parametro
 *
 * @param this LinkedList*
 * @param nodeIndex int
 * @return retorna NULL si hubo error o un puntero al nodo que se encuentra en la posicion solicitadas
 */
Node* getNode(LinkedList* this , int nodeIndex)
{
	Node* auxNode = NULL;
	int len;
	int i;

	if(this != NULL && nodeIndex > -1)
	{
		len = linkedlist_len(this);
		if(nodeIndex < len)
		{
			auxNode = this->pFirstNode;
			for(i = 0; i < nodeIndex; i++)
			{
				auxNode = auxNode->pNextNode;
			}
		}
	}

	return auxNode;
}
/**
 * @fn int addNode(LinkedList*, int, void*)
 * @brief agrega un nodo en la posicion especificada por parametro
 *
 * @param this LinkedList*
 * @param nodeIndex int
 * @param pElement void*
 * @return retorna -1 si hubo error o 0 si el nodo pudo ser agregado
 */
int addNode(LinkedList* this , int nodeIndex , void* pElement)
{
	Node* previousNode;
	Node* actualNode;
	int ret = -1;
	int len;

	if(this != NULL && nodeIndex > -1)
	{
		len = linkedlist_len(this);
		if(nodeIndex < len + 1)
		{
			actualNode = (Node*) malloc (sizeof(Node));
			actualNode->pElement = pElement;

			if(nodeIndex == 0)
			{
				actualNode->pNextNode = this->pFirstNode;
				this->pFirstNode = actualNode;
			}

			else if(nodeIndex > 0 && nodeIndex < len)
			{
				previousNode = getNode(this, nodeIndex - 1);
				actualNode->pNextNode = previousNode->pNextNode;
				previousNode->pNextNode = actualNode;
			}

			else
			{
				previousNode = getNode(this, nodeIndex - 1);
				previousNode->pNextNode = actualNode;
				actualNode->pNextNode = NULL;
			}
		}

		this->size++;
		ret = 0;
	}

	return ret;
}

/*--------------------------------CONSTRUCTORS--------------------------------*/

/**
 * @fn LinkedList linkedlist_new*()
 * @brief crea una nueva linkedlist
 *
 * @return retorna NULL si hubo error o la direccion de memoria del puntero a la nueva linkedlist
 */
LinkedList* linkedlist_new()
{
	LinkedList* new = (LinkedList*) malloc (sizeof(LinkedList));
	if(new != NULL)
	{
		new->size = 0;
		new->pFirstNode = NULL;
	}

	return new;
}

/*--------------------------------UTILITIES--------------------------------*/

/**
 * @fn int linkedlist_len(LinkedList*)
 * @brief consigue el tamanio de la linkedlist
 *
 * @param this LinkedList*
 * @return retorna -1 si hubo error o el tamanio de la linkedlist si funciona
 */
int linkedlist_len(LinkedList* this)
{
	int ret = -1;

	if(this != NULL)
	{
		ret = this->size;
	}

	return ret;
}

/**
 * @fn int linkedlist_add(LinkedList*, void*)
 * @brief agrega un elemento al final de la linkedlist
 *
 * @param this LinkedList*
 * @param pElement void*
 * @return retorna -1 si hubo error o 0 si el nodo pudo ser agregado correctamente
 */
int linkedlist_add(LinkedList* this, void* pElement)
{
	int ret = -1;
	int len;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		ret = addNode(this, len, pElement);
	}

	return ret;
}
/**
 * @fn void linkedlist_get*(LinkedList*, int)
 * @brief obtiene el elemento que se encuentra en la posicion de la linkedlist especificada
 *
 * @param this LinkedList*
 * @param index int
 * @return retorna NULL si hubo error o el puntero al elemento encontrado si funciono correctamente
 */
void* linkedlist_get(LinkedList* this, int index)
{
	Node* node = NULL;
	void* ret = NULL;
	int len;

	if(this != NULL && index > -1)
	{
		len = linkedlist_len(this);
		if(index < len)
		{
			node = getNode(this, index);
			ret = node->pElement;
		}
	}

	return ret;
}

/**
 * @fn int linkedlist_remove(LinkedList*, int)
 * @brief elimina un elemento de la linkedlist
 *
 * @param this LinkedList*
 * @param index int
 * @return retorna -1 si hubo error o 0 si el elemento se elimino correctamente
 */
int linkedlist_remove(LinkedList* this, int index)
{
	Node* auxNode = NULL;
	Node* previousNode = NULL;
	int ret = -1;
	int len;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		if(index > -1 && index < len)
		{

			if(!index)
			{
				auxNode = this->pFirstNode;
				this->pFirstNode = auxNode->pNextNode;

			}

			else if(index > 0 && index < len)
			{
				auxNode = getNode(this, index);
				previousNode = getNode(this, index - 1);
				previousNode->pNextNode = auxNode->pNextNode;
			}

			else
			{
				previousNode = getNode(this, index - 1);
				previousNode->pNextNode = NULL;
			}

			this->size--;
			free(auxNode);
			auxNode = NULL;

			ret = 0;
		}
	}

	return ret;
}
/**
 * @fn int linkedlist_set(LinkedList*, int, void*)
 * @brief modifica un elemento a la linkedlist
 *
 * @param this LinkedList*
 * @param index int
 * @param pElement void*
 * @return retorna -1 si hubo error o 0 si el elemento pudo ser modificado correctamente
 */
int linkedlist_set(LinkedList* this, int index, void* pElement)
{
	Node* auxNode = NULL;
	int ret = -1;
	int len;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		if(index > -1 && index < len)
		{
			auxNode = getNode(this, index);
			auxNode->pElement = pElement;
			ret = 0;
		}
	}

	return ret;
}
/**
 * @fn int linkedlist_clear(LinkedList*)
 * @brief elimina todos los elementos de la linkedlist
 *
 * @param this LinkedList*
 * @return retorna -1 si hubo error o 0 si se pudieron eliminar todos los elementos
 */
int linkedlist_clear(LinkedList* this)
{
	int ret = -1;
	int len;
	int i;

	if(this != NULL)
	{
		len = linkedlist_len(this);
		for(i = 0; i < len; i++)
		{
			linkedlist_remove(this, i);
		}

		ret = 0;
	}

	return ret;
}


/**
 * @fn int linkedlist_delete(LinkedList*)
 * @brief elimina una linkedlist
 *
 * @param this LinkedList*
 * @return retorna -1 si hubo error o 0 si la lista pudo ser eliminada
 */
int linkedlist_delete(LinkedList* this)
{
	int ret = -1;

	if(this != NULL)
	{
		linkedlist_clear(this);
		free(this);
		this = NULL;
		ret = 0;
	}

	return ret;
}
/**
 * @fn int linkedlist_sort(LinkedList*, int, int(*)(void*, void*))
 * @brief ordena los elementos de una linkedlist con el criterio que retorne de la funcion que se pasa por parametro
 *
 * @param this LinkedList*
 * @param order int
 * @param pointerTofunction (*pointerToFunction)
 * @return retorna -1 si hubo error o 0 si pudo realizar el ordenamiento correctamente
 */
int linkedlist_sort(LinkedList* this, int (*pointerToFunction)(void*, void*), int order)
{
	void* aux;
	void* element1;
	void* element2;
	int returnFunction;
	int ret = -1;
	int len;
	int i;
	int j;

	if(this != NULL && pointerToFunction != NULL && (order == 0 || order == 1))
	{
		len = linkedlist_len(this);
		for(i = 0; i < len - 1; i++)
		{
			element1 = linkedlist_get(this, i);
			for(j = i + 1; j < len; j++)
			{
				element2 = linkedlist_get(this, j);
				returnFunction = pointerToFunction(element1, element2);
				if(order == 0)
				{
					if(returnFunction == -1)
					{
						aux = element1;
						element1 = element2;
						element2 = aux;
					}
				}

				if ( order == 1)
				{
					if ( returnFunction == 1)
					{
						aux = element2;
						element2 = element1;
						element1 = aux;
					}
				}

				linkedlist_set(this, i, element1);
				linkedlist_set(this, j, element2);
			}
		}
		ret = 0;
	}
	return ret;
}


















