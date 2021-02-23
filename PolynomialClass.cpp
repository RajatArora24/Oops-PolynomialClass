class Polynomial {
    
     public:
    
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    Polynomial()  //Default Constructor
    {
        degCoeff=new int[100];
        capacity=100;
        for(int i=0;i<capacity;i++)
        {
            degCoeff[i]=0;
        }
        
    }
    
    
    Polynomial(const Polynomial &p)    //Copy constructor
    {
    	this->degCoeff=new int[p.capacity];
        this->capacity=p.capacity;
        for(int i=0;i<capacity;i++)
        {
            degCoeff[i]=p.degCoeff[i];
        }
    }
    
     Polynomial operator *(const Polynomial &P)const
    {	
          Polynomial ans;
         ans.degCoeff=new int[100];
         ans.capacity=100;
         for(int i=0;i<ans.capacity;i++)
        	{
            	ans.degCoeff[i]=0;
        	}
        	
        	
         for(int i=0;(i<this->capacity) ;i++)
         {
         	if (this->degCoeff[i]!=0)
         	{
			
             int degree=i;
             for(int j=0;j<P.capacity ;j++)
             {
             	if (P.degCoeff[j]!=0)
         		{
                 degree=degree+j;
                 ans.degCoeff[degree]=ans.degCoeff[degree]+(degCoeff[i]*P.degCoeff[j]);
                 degree=i;    
             	}
                 
             }
        	}
         }
         
		return ans;
    }
    
    
    void setCoefficient(int degree, int coefficient)
    {
        if(degree>=capacity)
        {  
            int size=degree+5;
         	int *NewdegCoeff= new int[size];
            for(int i=0;i<capacity;i++)
            {
        
                NewdegCoeff[i]=degCoeff[i];
            }
            for(int i=capacity;i<size;i++)
            {
                
                NewdegCoeff[i]=0;
            }
        	capacity=size;
            delete [] degCoeff;
            degCoeff=NewdegCoeff;
         	   
        }
        
            
        degCoeff[degree]=coefficient;
        
        
        
    }
    
    Polynomial operator +(const Polynomial &P)const
    {
        
        Polynomial ans;
        int size=max(capacity,P.capacity);
        ans.capacity=size;
        
        for(int i=0;i<size;i++)
        {
            ans.degCoeff[i]=0;
        } 
    
        for(int i=0;i<size;i++)
        {
            ans.degCoeff[i]=degCoeff[i]+P.degCoeff[i];
        }
        return ans;
        
        
    }
    
    
    Polynomial operator -(const Polynomial &P)const
    {
        Polynomial ans;
        int size=max(capacity,P.capacity);
        ans.capacity=size;
        ans.degCoeff[size]={0};
            
        for(int i=0;i<size;i++)
        {
            ans.degCoeff[i]=degCoeff[i]-P.degCoeff[i];
        }
        return ans;
        
    }

    void operator =(const Polynomial &p)
    {
        this->degCoeff=new int[p.capacity];
        this->capacity=p.capacity;
        for(int i=0;i<capacity;i++)
        {
            this->degCoeff[i]=p.degCoeff[i];
        }
    }
    
    void print()
    {
        for(int i=0;i<capacity;i++)
        {
            if(this->degCoeff[i]!=0)
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }
    
};
