### LINEAR SEARCH
```
PROCEDURE linearSearch(INT n , INT x, INT A[n])
    FOR i = 0 TO n - 1
        IF A[i] == x THEN
            RETURN i
        END IF
    END FOR
    RETURN -1
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i, x
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    PRINT "ENTER THE ELEMENT TO BE SEARCHED: "
    READ x

    DECLARE INT index
    SET index = linearSearch(arr, n, x)
    IF index == -1 THEN
        PRINT "ELEMENT NOT FOUND."
    ELSE
        PRINT "THE POSITION IS: ", index
    END IF
END PROCEDURE

```

### BINARY SEARCH
```
PROCEDURE binarySearch(int A[], INT l, INT h , INT x) 
    IF l <= h THEN
        DECLARE INT mid
        SET mid = (l + h) / 2

        IF A[mid] == x THEN
            RETURN mid
        ELSE IF A[mid] > x THEN
            RETURN binarySearch(A, l, mid - 1, x)
        ELSE
            RETURN binarySearch(A, mid + 1, h, x)
        END IF
    END IF

    RETURN -1
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i, x
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    PRINT "ENTER THE ELEMENT TO BE SEARCHED: "
    READ x

    DECLARE INT index
    SET index = binarySearch(arr, 0, n - 1, x)

    IF index == -1 THEN
        PRINT "ELEMENT NOT FOUND."
    ELSE
        PRINT "THE POSITION IS: ", index
    END IF
END PROCEDURE

```

### BUBBLE SORT
```
PROCEDURE swap(INT *x, INT *y)
    DECLARE INT temp
    SET temp = *x
    *x = *y
    *y = temp
END PROCEDURE

PROCEDURE bubbleSort(INT n , INT A[])
    DECLARE INT i, j, comp
    FOR i = 0 TO n - 1
        SET comp = 0
        FOR j = 0 TO n - i - 1
            IF A[j] > A[j + 1] THEN
                CALL swap(&A[j], &A[j + 1])
                INCREMENT comp BY 1
            END IF
        END FOR
        IF comp == 0 THEN
            BREAK
        END IF
    END FOR
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i, x
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    CALL bubbleSort(n , arr)

    PRINT "THE SORTED ARRAY IS: "
    FOR i = 0 TO n - 1
        PRINT arr[i]
    END FOR
END PROCEDURE

```

### REPEATED ELEMENTS IN A STRING
```
PROCEDURE main()
    DECLARE INT ascii[129]
    SET all elements of ascii to 0

    DECLARE CHAR str[1000]
    PRINT "ENTER THE STRING: "
    READ str

    FOR i = 0 TO (length of str - 1)
        INCREMENT ascii[(int)str[i]] BY 1

    PRINT "REPEATED ELEMENTS ARE: "
    FOR i = 0 TO 129
        IF ascii[i] > 1 AND i != 32
            PRINT i AS CHARACTER, "-", ascii[i]
        END IF
    END FOR
END PROCEDURE

```

### SECOND LARGEST ELEMENT
```
SECOND LARGEST ELEMENT

PROCEDURE swap(INT *x , INT *y)
    DECLARE INT temp
    SET temp = *x
    *x = *y
    *y = temp
END PROCEDURE

PROCEDURE bubbleSort(INT n ,INT A[])
    DECLARE INT i, j, comp
    FOR i = 0 TO 2
        SET comp = 0
        FOR j = 0 TO n - i - 1
            IF A[j] > A[j + 1] THEN
                CALL swap(&A[j], &A[j + 1])
                INCREMENT comp BY 1
            END IF
        END FOR
        IF comp == 0 THEN
            BREAK
        END IF
    END FOR
    RETURN A[n - 2]
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i, x, m

    PRINT "ENTER THE NUMBER OF ELEMENTS: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    PRINT "SECOND LARGEST ELEMENT IS: ", bubbleSort(n, arr)
END PROCEDURE

```

### SELECTION SORT
```
PROCEDURE swap(INT *x , INT *y)
    DECLARE INT temp
    SET temp = *x
    *x = *y
    *y = temp
END PROCEDURE

PROCEDURE selectionSort(INT A[] , INT n)
    DECLARE INT i, j, minIndex
    FOR i = 0 TO n - 1
        SET minIndex = i
        FOR j = i + 1 TO n
            IF A[j] < A[minIndex] THEN
                SET minIndex = j
            END IF
        END FOR
        IF minIndex != i THEN
            CALL swap(&A[i], &A[minIndex])
        END IF
    END FOR
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    CALL selectionSort(arr, n)

    PRINT "THE SORTED ARRAY IS: "
    FOR i = 0 TO n - 1
        PRINT arr[i]
    END FOR
END PROCEDURE

```

### INSERTION SORT
```
PROCEDURE insertionSort(INT A[] , INT n)
    DECLARE INT i, j, key
    FOR i = 1 TO n - 1
        SET key = A[i]
        SET j = i - 1

        WHILE j >= 0 AND A[j] > key
            SET A[j + 1] = A[j]
            DECREMENT j BY 1
        END WHILE

        SET A[j + 1] = key
    END FOR
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    CALL insertionSort(arr, n)
    
    PRINT "THE SORTED ARRAY IS: "
    FOR i = 0 TO n - 1
        PRINT arr[i]
    END FOR
END PROCEDURE

```

### POLYNOMIAL ADDITION
```
STRUCT term
    DECLARE INT exp, coeff
END STRUCT

STRUCT poly
    DECLARE INT n
    DECLARE term arr[500]
END STRUCT

PROCEDURE main()
    DECLARE poly p1, p2, p3
    DECLARE INT i, j, k
    SET p3.n = 0

    PRINT "ENTER THE NUMBER OF TERMS IN P1: "
    READ p1.n

    FOR i = 0 TO p1.n - 1
        PRINT "ENTER THE COEFF AS WELL AS EXP: "
        READ p1.arr[i].coeff, p1.arr[i].exp
    END FOR

    PRINT "ENTER THE NUMBER OF TERMS IN P2: "
    READ p2.n

    FOR i = 0 TO p2.n - 1
        PRINT "ENTER THE COEFF AS WELL AS EXP: "
        READ p2.arr[i].coeff, p2.arr[i].exp
    END FOR

    PRINT "FIRST: "
    FOR i = 0 TO p1.n - 1
        PRINT p1.arr[i].coeff, "x^", p1.arr[i].exp
        IF i == p1.n - 1
            PRINT " "
        ELSE
            PRINT " + "
        END IF
    END FOR

    PRINT "SECOND: "
    FOR i = 0 TO p2.n - 1
        PRINT p2.arr[i].coeff, "x^", p2.arr[i].exp
        IF i == p2.n - 1
            PRINT " "
        ELSE
            PRINT " + "
        END IF
    END FOR
    
    SET i = 0
    SET j = 0
    SET k = 0

    WHILE i < p1.n AND j < p2.n
        IF p1.arr[i].exp == p2.arr[j].exp
            SET p3.arr[k].exp = p1.arr[i].exp
            SET p3.arr[k].coeff = p1.arr[i].coeff + p2.arr[j].coeff
            INCREMENT i BY 1
            INCREMENT j BY 1
        ELSE IF p1.arr[i].exp < p2.arr[j].exp
            SET p3.arr[k].exp = p1.arr[i].exp
            SET p3.arr[k].coeff = p1.arr[i].coeff
            INCREMENT i By 1
        ELSE
            SET p3.arr[k].exp = p2.arr[j].exp
            SET p3.arr[k].coeff = p2.arr[j].coeff
            INCREMENT j BY 1
        END IF
        INCREMENT k BY 1
        INCREMENT p3.n BY 1
    END WHILE

    FOR i = i TO p1.n - 1
        SET p3.arr[k].exp = p1.arr[i].exp
        SET p3.arr[k].coeff = p1.arr[i].coeff
        INCREMENT k BY 1
        INCREMENT p3.n BY 1
    END FOR

    FOR j = j TO p2.n - 1
        SET p3.arr[k].exp = p2.arr[j].exp
        SET p3.arr[k].coeff = p2.arr[j].coeff
        INCREMENT k BY 1
        INCREMENT p3.n BY 1
    END FOR

    PRINT "SUM: "
    FOR i = 0 TO p3.n - 1
        PRINT p3.arr[i].coeff, "x^", p3.arr[i].exp
        IF i == p3.n - 1
            PRINT "\n"
        ELSE
            PRINT " + "
        END IF
    END FOR
END PROCEDURE

```

### STACK
```
STRUCT stack
    DECLARE INT top, size
    DECLARE INT arr[100]
END STRUCT

PROCEDURE isFull(STRUCT stack *st) 
    RETURN (st->size == st->top + 1)
END PROCEDURE

PROCEDURE isEmpty(STRUCT stack *st) 
    RETURN (st->top == -1)
END PROCEDURE

PROCEDURE push(STRUCT stack *st,INT ele)
    IF isFull(st) THEN
        PRINT "STACK IS FULL."
    ELSE
        st->arr[++(st->top)] = ele
    END IF
END PROCEDURE

PROCEDURE pop(STRUCT stack *st)
    IF isEmpty(st) THEN
        PRINT "STACK IS EMPTY."
    ELSE
        PRINT st->arr[(st->top)--]
    END IF
END PROCEDURE

PROCEDURE peek(STRUCT stack *st)
    IF isEmpty(st) THEN
        PRINT "STACK IS EMPTY."
    ELSE
        PRINT st->arr[st->top]
    END IF
END PROCEDURE

PROCEDURE displayMenu()
    PRINT "\n------ MENU ------"
    PRINT "1. PUSH"
    PRINT "2. POP"
    PRINT "3. PEEK"
    PRINT "4. EXIT"
    PRINT "-------------------"
END PROCEDURE

PROCEDURE main()
    DECLARE STACK st
    st.top = -1

    PRINT "ENTER THE SIZE OF STACK: "
    READ st.size

    DECLARE INT choice, ele
    set choice = 0 

    WHILE choice != 4
        CALL displayMenu()
        PRINT "ENTER THE CHOICE: "
        READ choice

        SWITCH (choice)
            CASE 1
                PRINT "ENTER THE NUMBER: "
                READ ele
                CALL push(&st, ele)
            CASE 2
                CALL pop(&st)
            CASE 3
                CALL peek(&st)
            CASE 4
                PRINT "EXITING."
            DEFAULT
                PRINT "WRONG CHOICE."
        END SWITCH

        PRINT "\n"
    END WHILE
END PROCEDURE

```

### QUEUE
```
STRUCT queue
    DECLARE INT size
    DECLARE INT rear
    DECLARE INT front
    DECLARE INT arr[100]
END STRUCT

PROCEDURE isFull(q)
    RETURN (q.rear == q.size - 1)
END PROCEDURE

PROCEDURE isEmpty(q)
    RETURN (q.front == q.rear)
END PROCEDURE

PROCEDURE enqueue(q, n)
    IF isFull(q) THEN
        PRINT "QUEUE IS FULL."
    ELSE
        q.arr[++(q.rear)] = n
    END IF
END PROCEDURE

PROCEDURE dequeue(q)
    IF isEmpty(q) THEN
        PRINT "THE QUEUE IS EMPTY."
    ELSE
        PRINT q.arr[++(q.front)]
    END IF
END PROCEDURE

PROCEDURE display(q)
    IF isEmpty(q) THEN
        PRINT "QUEUE IS EMPTY."
    ELSE
        FOR i = q.front + 1 TO q.rear
            PRINT q.arr[i]
        END FOR
    END IF
END PROCEDURE

PROCEDURE displayMenu()
    PRINT "------ MENU ------"
    PRINT "1. ENQUEUE"
    PRINT "2. DEQUEUE"
    PRINT "3. DISPLAY"
    PRINT "4. EXIT"
    PRINT "-------------------"
END PROCEDURE

PROCEDURE main()
    DECLARE INT q
    q.front = q.rear = -1

    PRINT "ENTER THE SIZE OF QUEUE : "
    READ q.size

    DECLARE INT choice, n
    SET choice = 0

    WHILE choice != 4
        displayMenu()
        PRINT "ENTER CHOICE : "
        READ choice

        SWITCH choice
            CASE 1:
                PRINT "ENTER THE ELEMENT : "
                READ n
                enqueue(q, n)
                BREAK
            CASE 2:
                dequeue(q)
                BREAK
            CASE 3:
                display(q)
                BREAK
            CASE 4:
                PRINT "EXITING."
                BREAK
            DEFAULT:
                PRINT "WRONG CHOICE."
        END SWITCH
    END WHILE
END PROCEDURE

```

### SPARSE MATRIX REPRESENTATION
```
PROCEDURE insertElements(m, n, A)
    DECLARE INT i,j
    PRINT "ENTER THE ELEMENTS"
    FOR i = 0 TO m - 1
        PRINT "ENTER THE ROW ", i + 1, " : "
        FOR j = 0 TO n - 1
            READ A[i][j]
        END FOR
    END FOR
END PROCEDURE

PROCEDURE display(m, n, A)
    DECLARE INT i,j
    PRINT "THE SPARSE MATRIX IS :"
    FOR i = 0 TO m - 1
        FOR j = 0 TO n - 1
            PRINT A[i][j], " "
        END FOR
        PRINT "\n"
    END FOR
END PROCEDURE

PROCEDURE convertToThreeTuple(r, c, A, C)
    DECLARE INT i,j,k = 1

    FOR i = 0 TO r - 1
        FOR j = 0 TO c - 1
            IF A[i][j] != 0 THEN
                C[k][0] = i
                C[k][1] = j
                C[k][2] = A[i][j]
                INCREMENT k
            END IF
        END FOR
    END FOR

    C[0][0] = r
    C[0][1] = c
    C[0][2] = k - 1
    RETURN k
END PROCEDURE

PROCEDURE main()
    DECLARE INT r, c
    PRINT "ENTER THE ROW AND COLUMN OF MATRIX : "
    READ r, c

    DECLARE INT A[r][c], C[r * c][3]

    insertElements(r, c, A)

    DECLARE INT k1 = convertToThreeTuple(r, c, A, C)

    display(k1, 3, C)
END PROCEDURE

```

### SPARSE MATRIX ADDITION
```
FUNCTION insertElements(m, n, A)
    DECLARE INT i,j
    PRINT "ENTER THE ELEMENTS"
    FOR i = 0 TO m - 1
        PRINT "ENTER THE ROW ", i + 1, " : "
        FOR j = 0 TO n - 1
            READ A[i][j]
        END FOR
    END FOR
END FUNCTION

FUNCTION display(m, n, A)
    DECLARE INT i,j
    PRINT "THE SPARSE MATRIX IS :"
    FOR i = 0 TO m - 1
        FOR j = 0 TO n - 1
            PRINT A[i][j], " "
        END FOR
        PRINT "\n"
    END FOR
END FUNCTION

FUNCTION convertToThreeTuple(r, c, A, C)
    DECLARE INT k = 1,i,j

    FOR i = 0 TO r - 1
        FOR j = 0 TO c - 1
            IF A[i][j] != 0 THEN
                C[k][0] = i
                C[k][1] = j
                C[k][2] = A[i][j]
                INCREMENT k
            END IF
        END FOR
    END FOR

    C[0][0] = r
    C[0][1] = c
    C[0][2] = k - 1
    RETURN k
END FUNCTION

FUNCTION addSparseMatrices(A, B, C)
    DECLARE INT i = 1, j = 1, k = 1
    DECLARE INT m = A[0][2], n = B[0][2]

    WHILE i <= m AND j <= n
        IF A[i][0] < B[j][0] OR (A[i][0] == B[j][0] AND A[i][1] < B[j][1]) THEN
            C[k][0] = A[i][0]
            C[k][1] = A[i][1]
            C[k][2] = A[i][2]
            INCREMENT i
        ELSE IF A[i][0] > B[j][0] OR (A[i][0] == B[j][0] AND A[i][1] > B[j][1]) THEN
            C[k][0] = B[j][0]
            C[k][1] = B[j][1]
            C[k][2] = B[j][2]
            INCREMENT j
        ELSE
            C[k][0] = A[i][0]
            C[k][1] = A[i][1]
            C[k][2] = A[i][2] + B[j][2]
            INCREMENT i
            INCREMENT j
        END IF
        INCREMENT k
    END WHILE

    WHILE i <= m
        C[k][0] = A[i][0]
        C[k][1] = A[i][1]
        C[k][2] = A[i][2]
        INCREMENT i
        INCREMENT k
    END WHILE

    WHILE j <= n
        C[k][0] = B[j][0]
        C[k][1] = B[j][1]
        C[k][2] = B[j][2]
        INCREMENT j
        INCREMENT k
    END WHILE

    C[0][0] = A[0][0]
    C[0][1] = A[0][1]
    C[0][2] = k - 1
    RETURN k
END FUNCTION

FUNCTION main()
    DECLARE INT r , c
    PRINT "ENTER THE ROW AND COLUMN OF MATRICES : "
    READ r, c

    DECLARE INT A[r][c], B[r][c], C[r * c][3], D[r * c][3]
    DECLARE INT result[r * c][3]

    insertElements(r, c, A)
    insertElements(r, c, B)

    DECLARE INT k1 = convertToThreeTuple(r, c, A, C)
    DECLARE INT k2 = convertToThreeTuple(r, c, B, D)
    DECLARE INT k3 = addSparseMatrices(C, D, result)

    display(k3, 3, result)
END FUNCTION

```

### CIRCULAR QUEUE
```
DECLARE INT items[100]; 
DECLARE INT front, rear,size
SET front = -1, rear= -1

PROCEDURE isFull()
    RETURN (front == rear + 1) OR (front == 0 AND rear == size - 1)
END PROCEDURE

PROCEDURE isEmpty()
    RETURN (front == -1)
END PROCEDURE

PROCEDURE enQueue(element)
    IF isFull() THEN
        PRINT "QUEUE IS FULL"
    ELSE
        IF front == -1 THEN
            front = 0
        END IF
        rear = (rear + 1) % size
        items[rear] = element
    END IF
END PROCEDURE

PROCEDURE deQueue()
    DECLARE element
    IF isEmpty() THEN
        PRINT "QUEUE IS EMPTY"
        RETURN -1
    ELSE
        element = items[front]
        IF front == rear THEN
            front = -1
            rear = -1
        ELSE
            front = (front + 1) % size
        END IF
        RETURN element
    END IF
END PROCEDURE

PROCEDURE display()
    DECLARE INT i
    IF isEmpty() THEN
        PRINT "QUEUE IS EMPTY"
    ELSE
        FOR i = front TO rear
            PRINT items[i]
        END FOR
    END IF
END PROCEDURE

PROCEDURE menu()
    PRINT "CHOICES..."
    PRINT "1. INSERT"
    PRINT "2. DELETE"
    PRINT "3. DISPLAY"
    PRINT "4. EXIT"
END PROCEDURE

PROCEDURE main()
    DECLARE INT choice, element
    PRINT "ENTER THE SIZE OF QUEUE : "
    READ size

    DO
        menu()
        PRINT "ENTER YOUR CHOICE :"
        READ choice
        SWITCH choice
            CASE 1:
                PRINT "ENTER ELEMENT TO BE INSERTED : "
                READ element
                enQueue(element)
                BREAK
            CASE 2:
                deQueue()
                BREAK
            CASE 3:
                display()
                BREAK
            CASE 4:
                PRINT "EXIT"
                BREAK
            DEFAULT:
                PRINT "INVALID CHOICE"
        END SWITCH
        PRINT ""
    WHILE choice != 4
END PROCEDURE

```

### INFIX TO POSTFIX
```
PROCEDURE isOperator(CHAR ch)
    IF ch is '+' OR ch is '-' OR ch is '*' OR ch is '/' OR ch is '^'
        RETURN 1
    ELSE
        RETURN 0
END PROCEDURE

PROCEDURE Precedence(CHAR ch)
    IF ch is '*' OR ch is '/'
        RETURN 2
    ELSE IF ch is '+' OR ch is '-'
        RETURN 1
    ELSE IF ch is '^'
        RETURN 3
    ELSE
        RETURN 0
END PROCEDURE

PROCEDURE infixToPostfix(CHAR INFIX[] . CHAR POSTFIX[])
    DECLARE CHAR stack[100]
    DECLARE INT top
    SET top = -1
    DECLARE INT i, j
    SET j = 0

    FOR i = 0 TO length of infix - 1
        IF infix[i] is '(' THEN
            SET stack[++top] = infix[i]
        ELSE IF infix[i] is ')' THEN
            WHILE stack[top] !=  '('
                SET postfix[j++] = stack[top--]
            END WHILE
            SET top = top - 1
        ELSE IF isOperator(infix[i]) THEN
            WHILE top is not -1 AND Precedence(stack[top]) >= Precedence(infix[i])
                SET postfix[j++] = stack[top--]
            END WHILE
            SET stack[++top] = infix[i]
        ELSE
            SET postfix[j++] = infix[i]
        END IF
    END FOR

    WHILE top is not -1
        SET postfix[j++] = stack[top--]
    END WHILE
    SET postfix[j] = '\0'
END PROCEDURE

PROCEDURE main()
    DECLARE CHAR infix[100]
    DECLARE CHAR postfix[100]

    PRINT "ENTER THE INFIX EXPRESSION: "
    READ infix

    CALL infixToPostfix(infix, postfix)

    PRINT "THE POSTFIX EXPRESSION IS : " + postfix
END PROCEDURE

```

### POSTFIX EVALUATION
```
DECLARE INT STACK[100] ; 
DECLARE INT TOP
SET TOP = -1PROCEDURE insertionSort(INT A[] , INT n)
    DECLARE INT i, j, key
    FOR i = 1 TO n - 1
        SET key = A[i]
        SET j = i - 1

        WHILE j >= 0 AND A[j] > key
            SET A[j + 1] = A[j]
            DECREMENT j BY 1
        END WHILE

        SET A[j + 1] = key
    END FOR
END PROCEDURE

PROCEDURE main()
    DECLARE INT n, i
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ARRAY ELEMENTS: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    CALL insertionSort(arr, n)
    
    PRINT "THE SORTED ARRAY IS: "
    FOR i = 0 TO n - 1
        PRINT arr[i]
    END FOR
END PROCEDURE

PROCEDURE push(INT x)
    stack[++top] = x
END PROCEDURE

PROCEDURE pop()
    RETURN stack[top--]
END PROCEDURE

PROCEDURE isOperator(CHAR ch) : integer
    IF ch is '+' OR ch is '-' OR ch is '*' OR ch is '/'
        RETURN 1
    ELSE
        RETURN 0
END PROCEDURE

PROCEDURE Precedence(CHAR ch) : integer
    IF ch is '*' OR ch is '/'
        RETURN 2
    ELSE IF ch is '+' OR ch is '-'
        RETURN 1
    ELSE
        RETURN 0
END PROCEDURE

PROCEDURE operation(INT a , INT b , CHAR ch) : integer
    IF ch is '+'
        RETURN a + b
    ELSE IF ch is '-'
        RETURN a - b
    ELSE IF ch is '*'
        RETURN a * b
    ELSE IF ch is '/'
        RETURN a / b
END PROCEDURE

PROCEDURE postfixEval(CHAR POSTFIX[]) : integer
    DECLARE INT res
    SET res = 0

    FOR i = 0 TO length of postfix - 1
        IF isOperator(postfix[i]) is 0 THEN
            push(postfix[i] - '0')
        ELSE
            DECLARE INT a
            DECLARE INT b
            SET a = pop()
            SET b = pop()
            SET res = operation(b, a, postfix[i])
            push(res)
        END IF
    END FOR

    RETURN res
END PROCEDURE

PROCEDURE main()
    DECLARE CHAR postfix[]
    PRINT "ENTER THE EXPRESSION: "
    READ postfix
    DECLARE INT res
    SET res = postfixEval(postfix)
    PRINT "THE RESULT IS : " + res
END PROCEDURE

```

### MERGE SORT
```
PROCEDURE merge(INT arr[] , INT l , INT m, INT r)
    DECLARE INT i, j, k
    DECLARE INT n1, n2

    SET n1 = m - l + 1
    SET n2 = r - m

    DECLARE INT L[n1]
    DECLARE INT R[n2]

    FOR i = 0 TO n1 - 1
        SET L[i] = arr[l + i]
    END FOR

    FOR j = 0 TO n2 - 1
        SET R[j] = arr[m + 1 + j]
    END FOR

    SET i = 0
    SET j = 0
    SET k = l

    WHILE i < n1 AND j < n2
        IF L[i] <= R[j] THEN
            SET arr[k] = L[i]
            INCREMENT i BY 1
        ELSE
            SET arr[k] = R[j]
            INCREMENT j BY 1
        END IF
        INCREMENT k BY 1
    END WHILE

    WHILE i < n1
        SET arr[k] = L[i]
        INCREMENT i
        INCREMENT k
    END WHILE

    WHILE j < n2
        SET arr[k] = R[j]
        INCREMENT j
        INCREMENT k
    END WHILE
END PROCEDURE

PROCEDURE mergeSort(INT arr[] , INT l , INT r)
    IF l < r THEN
        DECLARE INT m
        SET m = (l+r)/2 

        CALL mergeSort(arr, l, m)
        CALL mergeSort(arr, m + 1, r)

        CALL merge(arr, l, m, r)
    END IF
END PROCEDURE

PROCEDURE main()
    DECLARE INT n
    PRINT "ENTER THE SIZE OF ARRAY: "
    READ n

    DECLARE INT arr[n]
    PRINT "ENTER THE ELEMENTS OF ARRAY: "
    FOR i = 0 TO n - 1
        READ arr[i]
    END FOR

    CALL mergeSort(arr, 0, n - 1)

    PRINT "SORTED ARRAY: "
    FOR i = 0 TO n - 1
        PRINT arr[i]
    END FOR
END PROCEDURE

```

