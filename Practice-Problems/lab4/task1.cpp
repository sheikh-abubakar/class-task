#include <iostream>
using namespace std;

class Matrix {
private:
    int row;
    int col;
    int** ptr;

public:
    // Default Constructor
    Matrix() {
        row = 0;
        col = 0;
        ptr = nullptr;
    }

    // Parameterized Constructor
    Matrix(int r, int c) {
        row = r;
        col = c;
        ptr = new int* [row];
        for (int i = 0; i < row; i++) {
            ptr[i] = new int[col];
        }
    }

    // Copy Constructor
    Matrix(const Matrix& obj) {
        row = obj.row;
        col = obj.col;
        ptr = new int* [row];
        for (int i = 0; i < row; i++) {
            ptr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                ptr[i][j] = obj.ptr[i][j];
            }
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }

    // Get element at position (i, j)
    int get(int i, int j) {
        return ptr[i][j];
    }

    // Set element at position (i, j)
    void set(int i, int j, int val) {
        ptr[i][j] = val;
    }

    int& cell(int i, int j){
        return ptr[i][j];
    }

    // Input matrix values
    void inputMatrix() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> cell(i, j);
            }
        }
    }

    void resizeMatrx(int n_rows, int n_cols){

        int** newPtr = new int*[n_rows];
        for(int i =0;i<n_rows; i++){
            newPtr[i] = new int[n_cols];
        }

        for(int i = 0;i< row &&  i <n_rows; i++){
            for(int j =0; j< col && j<n_cols; j++){
                newPtr[i][j] = ptr[i][j];
            }
        }

        if(n_rows > row || n_cols > col){
            cout<<"enter entries for new matrix of new indexes";
            for(int i = 0; i < n_rows; i++){
                for(int j = 0; j< n_cols; j++){
                    if(i >= row || j >= col){
                        cout <<"Enter element [" << i + 1 << "][" << j + 1 << "]: ";
                        cin >>newPtr[i][j];
                    }
                }
            }
        }

        for(int i = 0; i <row; i++){
            delete [] ptr[i];
        }
        delete [] ptr;

        ptr = newPtr;
        row = n_rows;
        col = n_cols;

    }

    // Output matrix values
    void outputMatrix() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << cell(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Check if the matrix is square
    bool isSquare() {
        return row == col;
    }

        bool isEqual(const Matrix& m){
        if(isSquare()){
            return false;
        }

        for(int  i =0; i < row; i++){
            for(int j =0; j < col; j++){
                if(ptr[i][j] != m.ptr[i][j]){
                    return false;
                }
            }
    }
    return true;
    }

     bool isLowerTriangular(){
        if(!isSquare()){
            return false;
        }

        for(int i =0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i < j && ptr[i][j] != 0){
                    return false;
                }
            }
        }
        return true;
    }

    
    bool isUpperTriangular(){
        if(!isSquare()){
            return false;
        }

        for(int i =0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i > j && ptr[i][j] != 0){
                    return false;
                }
            }
        }
        return true;
    }

    bool isNull(){
        if(!isSquare()){
            return false;
        }
        for(int i =0; i < row; i++){
            for(int j =0; j<col; j++){
                if(ptr[i][j]!=0){
                    return false;
                }
            }
        }
        return true;
    }

    bool isDiagonal(){
        if(!isSquare()){
            return false;
        }

        for(int i =0; i < row; i++)
        {
            for(int j =0; j< col; j++){
                if(i != j && ptr[i][j] != 0){
                    return false;
                }
            }
        }
          return true;  
    
    }

    bool isIdentity(){
        if(!isSquare()){
            return false;
        }

        for(int i =0; i <row; i++){
            for(int j =0; j< col;j++){
                if(i == j && ptr[i][j] !=1){
                    return false;
                }
            }
        }
        return true;
    }
    // Add two matrices
    Matrix add(Matrix& m) {
        Matrix result(row, col);
        if (row == m.row && col == m.col) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    result.cell(i, j) = cell(i, j)+ m.cell(i,j);
                }
            }
        }
        else {
            cout << "Matrices are not compatible for addition!" << endl;
        }
        return result;
    }

    // Subtract two matrices
    Matrix subtract(Matrix& m) {
        Matrix result(row, col);
        if (row == m.row && col == m.col) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    result.cell(i, j) = cell(i, j) - m.cell(i, j);
                }
            }
        }
        else {
            cout << "Matrices are not compatible for subtraction!" << endl;
        }
        return result;
    }

    // Transpose of the matrix
    Matrix transpose() {
        Matrix result(col, row);  // Rows and cols are swapped
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.cell(i, j) = cell(i, j);
            }
        }
        return result;
    }

     Matrix multiplication(Matrix &m){
        Matrix result(row, col);
        if(col == m.row){
            for(int i = 0; i < row; i++){
                //bcz resultant matix has rows of fisrt mat and cols of second mat
                for(int j = 0; j<m.col; j++){
                    result.cell(i, j) = 0;
                    for(int k = 0; k < col; k++){
                        result.cell(i, j) += cell(i, k) * m.cell(k, j);
                    }

                }
            }
            
        }
        return result;
     }
    
};

// Main function with menu-driven operations
int main() {
    int r, c;

    cout << "Enter the number of rows for the matrix: ";
    cin >> r;
    cout << "Enter the number of columns for the matrix: ";
    cin >> c;

    Matrix mat1(r, c);
    Matrix mat2(r, c);

    cout << "Enter the elements for the first matrix:" << endl;
    mat1.inputMatrix();
    cout << "Enter the elements for the second matrix:" << endl;
    mat2.inputMatrix();

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Matrices" << endl;
        cout << "2. Subtract Matrices" << endl;
        cout << "3. Transpose Matrix 1" << endl;
        cout << "4. Check if Matrix 1 is Square" << endl;
        cout << "5. Check if Matrices are equal" << endl;
        cout<<"6. Check if Matrix 1 is lower Triangular" << endl;
        cout<< "7. Check if Matrix 1 is upper Triangular" << endl;
        cout<< "8. Check if Matrix 1 is null" << endl;
        cout<< "9. Check if Matrix 1 is diagonal" << endl;
        cout<< "10. Check if Matrix 1 is identity matrix" << endl;
        cout<< "11.Resize matrix" <<endl;
        cout << "12. Multiply two matrices"<<endl;

        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Matrix result = mat1.add(mat2);
            cout << "Result of Addition:" << endl;
            result.outputMatrix();
            break;
        }
        case 2: {
            Matrix result = mat1.subtract(mat2);
            cout << "Result of Subtraction:" << endl;
            result.outputMatrix();
            break;
        }
        case 3: {
            Matrix result = mat1.transpose();
            cout << "Transpose of Matrix 1:" << endl;
            result.outputMatrix();
            break;
        }
        case 4: {
            if (mat1.isSquare()) {
                cout << "Matrix 1 is a square matrix." << endl;
            }
            else {
                cout << "Matrix 1 is not a square matrix." << endl;
            }
            break;
        }

        case 5 : {
            if (mat1.isEqual(mat2)) {
                cout << "Matrices are equal." << endl;
            }
            else {
                cout << "Matrices are not equal." << endl;
            }
            break;
        }

        case 6 :{
            if(mat1.isLowerTriangular()){
                cout << "Matrix 1 is a lower triangular matrix." << endl;
            }
            else {
                cout << "Matrix 1 is not a lower triangular matrix." << endl;
            }
            break;
        }

        case 7 : {
            if(mat1.isUpperTriangular()){
                cout << "Matrix 1 is an upper triangular matrix." << endl;
            }
            else{
                cout<<"Matrix 1 is not an upper triangular matrix." << endl;
            }
            break;

        }

        case8: {
            if(mat1.isNull()){
                cout<<"matrix is null matrix"<<endl;
            }
            else{
                cout<<"matrix is not null matrix"<<endl;
            }
            break;
        }

        case 9: {
            if(mat1.isDiagonal()){
                cout<<"matrix 1 is diagonal"<<endl;
            }
            else{
                cout<<"matrix 1 is not diognal"<<endl;
            }

            break;
        }

        case 10:{
        if(mat1.isIdentity()){
             cout<<"matrix 1 is identity"<<endl;
        }
        else{
             cout<<"matrix 1 is not identity"<<endl;
        }
        break;
        }
        case 11:{
            int rows, cols;
            cout<<"enter rows and col for new matrix"<<endl;
            cin >> rows >> cols;

            mat1.resizeMatrx(rows, cols);
            mat1.outputMatrix();
        }
        case 12 : {
            Matrix result = mat1.multiplication(mat2);
            cout << "Result of multiply:" << endl;
            result.outputMatrix();
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
