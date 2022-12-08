    int rowSums[5];
    int colSums[4];
    int twoD[5][4];
    int i;
    int j;
    int k;
    int count;
    
    printString("Enter 20 ints: ");
    i = 0;
    count = 1;
    while (i < 5) {
        j = 0;
        while (j < 4) {
            twoD[i][j] = count;
            j = j + 1;
            count = count + 1;
        }
        i = i+1;
    }
    
    i = 0;
    while (i < 5) {
        j = 0;
        rowSums[i] = 0;
        while (j < 4) {
            rowSums[i] = rowSums[i] + twoD[i][j];
            j = j + 1;
        }
        i = i+1;
    }
    
    j = 0;
    while (j < 4) {
        i = 0;
        while (i < 5) {
            colSums[j] = colSums[j] + twoD[i][j];
            i = i + 1;
        }
        j = j+1;
    }
    
    i = 0;
     while (i < 5) {
         j = 0;
         print(rowSums[i]);
         printString(":\t");
         while (j < 4) {
             print(twoD[i][j]);
             printString("\t");
             j = j + 1;
         }
         printString("\n");
         i = i+1;
     }
    
    j = 0;
    printString("\t");
    while (j < 4) {
        print(colSums[j]);
        printString("\t");
        j = j+1;
    }
    printString("\n");
