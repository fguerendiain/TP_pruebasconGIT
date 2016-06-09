#ifndef __ARRAYLIST
#define __ARRAYLIST

/*--------------------------Struct ArrayList---------------------------------------------------------*/

struct ArrayList{
    int size;
    void **pElements;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

}typedef ArrayList;

/*-------------------------funciones privadas----------------------------------------------------------*/

int resizeUp(ArrayList* pList);     /**< Increment the number of elements in pList in AL_INCREMENT elements */

int resizeDown(ArrayList* pList);   /**< Decrement the number of elements in pList in AL_INCREMENT elements. */

int expand(ArrayList* pList,int index);     /**< Expand an array list */

int contract(ArrayList* pList,int index);   /**< Contract an array list */

/*--------------------------funciones ArrayList---------------------------------------------------------*/

ArrayList* al_newArrayList(void);     /**< Allocate a new arrayList with AL_INITIAL_VALUE elements */

int al_add(ArrayList* pList,void* pElement);     /**< Add an element to arrayList */

int al_deleteArrayList(ArrayList* pList);     /**< Delete arrayList */

int al_len(ArrayList* pList);     /**< Delete arrayList */

void* al_get(ArrayList* pList , int index);     /**< Get an element by index */

int al_contains(ArrayList* pList, void* pElement);     /**< Find if pList contains at least one element pElement */

int al_set(ArrayList* pList, int index,void* pElement);     /**< Set a element in pList at index position */

int al_remove(ArrayList* pList,int index);     /**< Remove an element by index */

int al_clear(ArrayList* pList);     /**< Removes all of the elements from this list */

ArrayList* al_clone(ArrayList* pList);     /**< Returns an array containing all of the elements in this list in proper sequence */

int al_push(ArrayList* pList, int index, void* pElement);     /**< Inserts the element at the specified position */

int al_indexOf(ArrayList* pList, void* pElement);     /**< Returns the index of the first occurrence of the specified element */

int al_isEmpty(ArrayList* pList);     /**< Returns true if this list contains no elements. */

void* al_pop(ArrayList* pList,int index);     /**< Remove the item at the given position in the list, and return it. */

ArrayList* al_subList(ArrayList* pList,int from,int to);     /**< Returns a new arrayList with a portion of pList */

int al_containsAll(ArrayList* pList,ArrayList* pList2);     /**< Returns true if pList list contains all of the elements of pList2 */

int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order);     /**< Sorts objects of list, use compare pFunc */

#endif //__ARRAYLIST
