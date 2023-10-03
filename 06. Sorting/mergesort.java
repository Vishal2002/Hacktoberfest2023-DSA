public class MergeSort {
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void merge(int[] arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int left[] = new int[n1];
        int right[] = new int[n2];
        int i, j, k;
        for (i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (j = 0; j < n2; j++) {
            right[j] = arr[mid + 1 + j];
        }
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        while (i < n1) {
            arr[k++] = left[i++];
        }
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }

    public static void mergerSort(int arr[], int l, int r) {
        // self work
        if (l >= r) {
            return;
        }
        int mid = (l + r) / 2;

        // recursive work
        mergerSort(arr, l, mid);
        mergerSort(arr, mid + 1, r);
        // self work
        merge(arr, l, mid, r);

    }

    public static void main(String[] args) {
        int arr[] = { 7, 20, 4, 11, 8, 2 };
        System.out.println("Array before sorting :-");
        printArray(arr);
        System.out.println();
        int n = arr.length;
        mergerSort(arr, 0, n - 1);
        System.out.println("Array after sorting :-");
        printArray(arr);

    }

}