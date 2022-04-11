#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char nama[50];
    int kode;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void insert(int val)
{
    struct node *ptr;
    for (int i = 0; i < val; i++)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("\nTake OFF ke-%d", i + 1);
        printf("\n-----------------");
        printf("\n Nama Pesawat : ");
        scanf("%s", ptr->nama);
        printf(" Kode Pesawat : ");
        scanf("%d", &ptr->kode);
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void delete_element()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("\n Silakan Masukkan data pesawat terlebih dahulu \n");
    else
    {
        front = front->next;
        printf("\n Pesawat \"%s\" dengan Kode \"%d\" telah Take OFF.\n\n", ptr->nama, ptr->kode);
        free(ptr);
    }
}

void peek()
{
    if (front == NULL)
        printf("\n Silakan Masukkan data pesawat terlebih dahulu \n");
    else
        printf("\n Pesawat \"%s\" dengan Kode \"%d\" akan segera Take OFF.\n\n", front->nama, front->kode);
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (ptr == NULL)
        printf("\n Silakan Masukkan data pesawat terlebih dahulu \n");
    else
    {
        printf("\n-----------------------------------------");
        printf("\n *** List Pesawat yang Akan Take OFF ***");
        printf("\n-----------------------------------------");
        printf("\n Nama Pesawat     | Kode Pesawat");
        printf("\n-----------------------------------------");
        while (ptr != rear)
        {
            if (ptr == front)
                printf("\n  %-15s | %-10d <-- front", ptr->nama, ptr->kode);
            else
                printf("\n  %-15s | %d", ptr->nama, ptr->kode);
            ptr = ptr->next;
        }
        if (ptr == front && ptr == rear)
                printf("\n  %-15s | %-10d <-- front & rear", ptr->nama, ptr->kode);
        else
            printf("\n  %-15s | %-10d <-- rear", ptr->nama, ptr->kode);
        printf("\n-----------------------------------------\n\n");
    }
}

int main()
{
    int val, option;
    do
    {
        printf("\n===========================================");
        printf("\n  Q U E U E   I M P L E M E N T A T I O N");
        printf("\n           \"Take OFF Pesawat\"");
        printf("\n===========================================");
        printf("\n 1. Tambah Pesawat");
        printf("\n 2. Pesawat Take OFF (Hapus)");
        printf("\n 3. Lihat Pesawat Akan Take OFF");
        printf("\n 4. List Pesawat Take OFF");
        printf("\n 5. Exit");
        printf("\n Masukkan pilihanmu : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nBerapa Pesawat yang ingin anda masukkan : ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            delete_element();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);
    return 0;
}