// tree.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

};

struct node* temp;
typedef struct node BTREE;

BTREE* new_node(int data)
{
    BTREE* p = new BTREE;
    p->data = data;
    p->left = NULL;
    p->right = NULL; 

    return p;

}


BTREE* insert(BTREE* root, int data)
{
    if (root != NULL)//ağaç boş değilse
    {
        //ekleyeceğimiz veri root'un data'sından küçükse
        if (data < root->data) //5<15
            root->left = insert(root->left, data);
        //ekleyeceğimiz veri root'un data'sından büyük veya eşitse
        else //20>15
            root->right = insert(root->right, data);
    }
    else //ağac boş ise
        root = new_node(data); //kök düğüm
    return root;
}

BTREE* tek(BTREE* root, BTREE* BSTTek) 
{
    if (root != NULL)
    {
        if (root->data % 2 == 1)
            BSTTek = insert(BSTTek, root->data);

        BSTTek = tek(root->left, BSTTek);
        BSTTek = tek(root->right, BSTTek);
    }
    return BSTTek;
}
BTREE* cift(BTREE* root, BTREE* BSTCift) 
{
    if (root != NULL)
    {
        if (root->data % 2 == 0)
            BSTCift = insert(BSTCift, root->data);

        BSTCift = cift(root->left, BSTCift);
        BSTCift = cift(root->right, BSTCift);
    }
    return BSTCift;

}

void preorder(BTREE* root) //kök-sol-sağ
{
    if (root != NULL)
    {
        cout << " " << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BTREE* root)//sol-kök-sağ
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << " " << root->data;
        inorder(root->right);
    }
}

void postorder(BTREE* root)//sol-sağ-kök
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << " " << root->data;
    }
}

int mirror(BTREE* root) //ayna
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        cout << root->data;
        mirror(temp = root->right);
        mirror(root->right = root->left);

    }

}
BTREE* searchTree(BTREE* tree, int data)
{
    if (tree != NULL)//Ağac doluysa
    {
        if (tree->data == data)
        {
            return tree;
        }
        else if (tree->data > data)
        {
            searchTree(tree->left, data);
        }
        else
        {
            searchTree(tree->right, data);
        }
    }
    else//Ağac boş ise 
    {
        return NULL;
    }
}

BTREE* delete_node(BTREE* root, int x)
{
    BTREE* p, * q;
    if (root == NULL) //Ağac yoksa
        return NULL;
    if (root->data == x) //Aranan düğümü bulduysak
    {
        //1.case (yaprak düğüm)
        if (root->left == root->right)
        {
            free(root);
            return NULL;
        }
        else //2.case (tek çocuklu düğüm siilnecek)
        {
            if (root->left == NULL)
            {
                p = root->right;
                free(root);
                return p;
            }
            else if (root->right == NULL)
            {
                p = root->left;
                free(root);
                return p;
            }
            else
            {
                p = q = root->right;
                while (p->left != NULL)
                {
                    p = p->left;
                }
                p->left = root->left;
                free(root);
                return q;
            }
        }
    }
    else if (root->data < x) //Aranan düğümü henüz bulamadıysa
        root->right = delete_node(root->right, x);
    else
        root->left = delete_node(root->left, x);
    return root;
}

int size(BTREE* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return size(root->left) + 1 + size(root->right);
    }
}

int height(BTREE* root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);
        return size(root->left) + 1 + size(root->right);

        if (right_height > left_height)
            return right_height + 1;
        else
            return left_height + 1;
    }
}

    int top;
    int z;
    int a = z;

int toplam(BTREE* root,int a)
{
    if (root != NULL)
    {
        top = a + root->data;  
        return (toplam(root->left, top) || toplam(root->right, top));
    }
   else
   {
        return  0;
   }
}


bool c = true;
bool d = false;

int esit(BTREE* root,int z)
{
    top = top - z;

    if (top == z)
    {
        cout << c;
    }
    else
    {
        cout << d;
    }
    return 0;
}

bool toplamm(BTREE* root, int a)
{
    if (root != NULL)
    {
        top = a + root->data;
        return (toplamm(root->left, top) || toplamm(root->right, top));
    }
    else
    {
        return  d;
    }
}

bool esitmi(BTREE* root, int z) 
{
    top = top - z;

    if (top == z) 
        cout<< c;
    else
        cout<< d;
    return 0;
}

int main()
{
    BTREE* root = NULL;
    BTREE* BSTTek = NULL;
    BTREE* BSTCift = NULL;
    int i = 0;
    int c= z;

    do
    {
        cout << "Agaca integer veri ekleyiniz..." << endl;
        cout << "Sayi : " << endl;
        cin >> i;
        if (i != -1)
            root = insert(root, i);
    } while (i != -1);

    cout << endl;
    cout << "Cift Sayilar (Preorder): ";
    BSTCift= cift(root,BSTCift);
    preorder(BSTCift);
    cout << endl;

    cout << endl;
    cout << "Tek Sayilar (Preorder): ";
    BSTTek = tek(root,BSTTek);
    preorder(BSTTek);
    cout << endl;

    cout << endl;
    cout << endl;
    cout << "Deger Giriniz : ";
    cin >> c;
    cout << endl;
    toplam(root,c);
    cout << "Int : ";
    esit(root,c);
    cout << endl;
    toplamm(root, c);
    cout << "Bool : ";
    esitmi(root,c);

    cout << endl;
    cout << endl;
    cout << "Dugumlerin Toplami : " << top;

   /*    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;*/
    
    /*
    cout << endl;
    cout << "Agacin Boyutu: " << size(cdroot) << endl;

    cout << endl;
    cout << "Agacin Yuksekligi: " << height(cdroot) << endl;*/

    /*cout << endl;
    cout << "Mirror(Ayna): ";
    mirror(cdroot);
    cout << endl;*/

    /* for (int syc = 0; syc < 3; syc++)
     {
         cout << endl;
         cout << "Silinecek sayi: ";
         cin >> i;
         delete_node(cdroot, i);
         inorder(cdroot);
     }*/

     /* cout << endl;
      cout << "Aranacak sayi: ";
      cin >> i;
      searchTree(cdroot, i);
      inorder(cdroot);*/
    return 1907;
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
