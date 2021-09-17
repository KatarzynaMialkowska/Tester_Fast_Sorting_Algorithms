#include "tester.hxx"
#include "gnuplot.hxx"

void test_sort_10k();
void test_sort_20k();
void test_sort_80k();
void test_sort_160k();

std::ofstream Hdata, Qdata, Mdata, Cdata, STDdata;
std::string HeapSortPlot("Hdata.dat");
std::string QuickSortPlot("Qdata.dat");
std::string MergeSortPlot("Mdata.dat");
std::string CSortPlot("Cdata.dat");
std::string StdPlot("STDdata.dat");
std::string name_graphs("graphs");
std::string type("pdf");

int main(){
   
    /*data needed for charts*/
    Hdata.open (HeapSortPlot, std::ios::out | std::ios::app); 
    Qdata.open (QuickSortPlot, std::ios::out | std::ios::app); 
    Mdata.open (MergeSortPlot, std::ios::out | std::ios::app); 
    Cdata.open (CSortPlot, std::ios::out | std::ios::app); 
    STDdata.open (StdPlot, std::ios::out | std::ios::app);

    test_sort_10k();
    test_sort_20k();
    test_sort_80k();
    test_sort_160k();

    /*create a chart*/
    gnuplot p;
    std::string setH("\'./" + HeapSortPlot + "\' u 1:2 w l");
    std::string setQ("\'./" + QuickSortPlot + "\' u 1:2 w l");
    std::string setM("\'./" + MergeSortPlot + "\' u 1:2 w l");
    std::string setC("\'./" + CSortPlot + "\' u 1:2 w l");
    std::string setSTD("\'./" + StdPlot + "\' u 1:2 w l");

    p("set terminal " + type);
    p("set output \"" + name_graphs + '.' + type + "\""); 
    p("set xlabel 'data'");
    p("set ylabel 't/s'");
    p("set title 'sortowanie szybkie'");

        p("set xrange [0:160000]");
        p("set yrange [0:0.01]");
    p("plot " + setH + " , " + setQ + " , " + setM + " , " + setC +  " , " + setSTD);
        p("set xrange [0:160000]");
        p("set yrange [0:0.099]");
    p("plot " + setH + " , " + setQ + " , " + setM + " , " + setC + " , "  + setSTD);
 

    Hdata.close();
    Qdata.close();
    Mdata.close();
    Cdata.close();
    STDdata.close();

    // test the sorts by giving copies of random numbers to the programs,

    /*test for 10000 data*/

   
    return 0;
}

void test_sort_10k(){
    std::vector<int> gen10000;
    int gen = 10000;
     // generate numbers to the vector
    generator(gen10000, gen, 10000);

    std::cout << "\t-TEST 10000 n-\n";

    /*test Heapsort sort for 10000 random number*/
    auto Hstart = std::chrono::high_resolution_clock::now();
        Heapsort(gen10000);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> HeapsortElapsed = Hend - Hstart;
    std::cerr << "Heapsort elapsed time[s] =" << HeapsortElapsed.count() << std::endl;
        Hdata << gen << '\t' << HeapsortElapsed.count() << '\n';

    /*test quicksort sort for 10000 random number*/
    auto Qstart = std::chrono::high_resolution_clock::now();
        quicksort(gen10000);
    auto Qend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quicksortElapsed = Qend - Qstart;
    std::cerr << "quicksort elapsed time[s] =" << quicksortElapsed.count() << std::endl;
        Qdata << gen << '\t' << quicksortElapsed.count() << '\n';

   /*test mergesort sort for 10000 random number*/
    auto Mstart = std::chrono::high_resolution_clock::now();
        mergesort(gen10000);
    auto Mend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortElapsed = Mend - Mstart;
    std::cerr << "mergesort elapsed time[s] =" << mergesortElapsed.count() << std::endl;
        Mdata << gen << '\t' << mergesortElapsed.count() << '\n';

    /*test c_sort sort for 10000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        c_sort(gen10000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> c_sortElapsed = Cend - Cstart;
    std::cerr << "c_sort elapsed time[s] =" << c_sortElapsed.count() << std::endl;
        Cdata << gen << '\t' << c_sortElapsed.count() << '\n';

     /*test std::sort sort for 10000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        std_sort(gen10000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> std_sortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << std_sortElapsed.count() << std::endl;
        STDdata << gen << '\t' << std_sortElapsed.count() << '\n';
}

void test_sort_20k(){
    std::vector<int> gen20000;
    int gen = 20000;
    // generate numbers to the vector
    generator(gen20000, gen, 10000);

    std::cout << "\t-TEST 20000 n-\n";

    /*test Heapsort sort for 20000 random number*/
    auto Q = std::chrono::high_resolution_clock::now();
        Heapsort(gen20000);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> HeapsortElapsed = Hend - Q;
    std::cerr << "Heapsort elapsed time[s] =" << HeapsortElapsed.count() << std::endl;
        Hdata << gen << '\t' << HeapsortElapsed.count() << '\n';

    /*test quicksort sort for 20000 random number*/
    auto Qstart = std::chrono::high_resolution_clock::now();
        quicksort(gen20000);
    auto Qend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quicksortElapsed = Qend - Qstart;
    std::cerr << "quicksort elapsed time[s] =" << quicksortElapsed.count() << std::endl;
        Qdata << gen << '\t' << quicksortElapsed.count() << '\n';

   /*test mergesort sort for 20000 random number*/
    auto Mstart = std::chrono::high_resolution_clock::now();
        mergesort(gen20000);
    auto Mend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortElapsed = Mend - Mstart;
    std::cerr << "mergesort elapsed time[s] =" << mergesortElapsed.count() << std::endl;
        Mdata << gen << '\t' << mergesortElapsed.count() << '\n';

    /*test c_sort sort for 20000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        c_sort(gen20000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> c_sortElapsed = Cend - Cstart;
    std::cerr << "c_sort elapsed time[s] =" << c_sortElapsed.count() << std::endl;
        Cdata << gen << '\t' << c_sortElapsed.count() << '\n';

     /*test std::sort sort for 20000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        std_sort(gen20000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> std_sortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << std_sortElapsed.count() << std::endl;
        STDdata << gen << '\t' << std_sortElapsed.count() << '\n';
}

void test_sort_80k(){
    std::vector<int> gen80000;
    int gen = 80000;
    // generate numbers to the vector
    generator(gen80000, gen, 10000);

    std::cout << "\t-TEST 80000 n-\n";

    /*test Heapsort sort for 80000 random number*/
    auto Hstart = std::chrono::high_resolution_clock::now();
        Heapsort(gen80000);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> HeapsortElapsed = Hend - Hstart;
    std::cerr << "Heapsort elapsed time[s] =" << HeapsortElapsed.count() << std::endl;
        Hdata << gen << '\t' << HeapsortElapsed.count() << '\n';

    /*test quicksort sort for 80000 random number*/
    auto Qstart = std::chrono::high_resolution_clock::now();
        quicksort(gen80000);
    auto Qend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quicksortElapsed = Qend - Qstart;
    std::cerr << "quicksort elapsed time[s] =" << quicksortElapsed.count() << std::endl;
        Qdata << gen << '\t' << quicksortElapsed.count() << '\n';
        
   /*test mergesort sort for 80000 random number*/
    auto Mstart = std::chrono::high_resolution_clock::now();
        mergesort(gen80000);
    auto Mend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortElapsed = Mend - Mstart;
    std::cerr << "mergesort elapsed time[s] =" << mergesortElapsed.count() << std::endl;
        Mdata << gen << '\t' << mergesortElapsed.count() << '\n';

    /*test c_sort sort for 80000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        c_sort(gen80000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> c_sortElapsed = Cend - Cstart;
    std::cerr << "c_sort elapsed time[s] =" << c_sortElapsed.count() << std::endl;
        Cdata << gen << '\t' << c_sortElapsed.count() << '\n';

     /*test std::sort sort for 80000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        std_sort(gen80000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> std_sortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << std_sortElapsed.count() << std::endl;
        STDdata << gen << '\t' << std_sortElapsed.count() << '\n';
}

void test_sort_160k(){
    std::vector<int> gen160000;
    int gen = 160000;
    // generate numbers to the vector
    generator(gen160000, gen, 10000);

    std::cout << "\t-TEST 160000 n-\n";

    /*test Heapsort sort for 160000 random number*/
    auto Hstart = std::chrono::high_resolution_clock::now();
        Heapsort(gen160000);
    auto Hend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> HeapsortElapsed = Hend - Hstart;
    std::cerr << "Heapsort elapsed time[s] =" << HeapsortElapsed.count() << std::endl;
        Hdata << gen << '\t' << HeapsortElapsed.count() << '\n';

    /*test quicksort sort for 160000 random number*/
    auto Qstart = std::chrono::high_resolution_clock::now();
        quicksort(gen160000);
    auto Qend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> quicksortElapsed = Qend - Qstart;
    std::cerr << "quicksort elapsed time[s] =" << quicksortElapsed.count() << std::endl;
        Qdata << gen << '\t' << quicksortElapsed.count() << '\n';

   /*test mergesort sort for 160000 random number*/
    auto Mstart = std::chrono::high_resolution_clock::now();
        mergesort(gen160000);
    auto Mend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortElapsed = Mend - Mstart;
    std::cerr << "mergesort elapsed time[s] =" << mergesortElapsed.count() << std::endl;
        Mdata << gen << '\t' << mergesortElapsed.count() << '\n';

    /*test c_sort sort for 160000 random number*/
    auto Cstart = std::chrono::high_resolution_clock::now();
        c_sort(gen160000);
    auto Cend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> c_sortElapsed = Cend - Cstart;
    std::cerr << "c_sort elapsed time[s] =" << c_sortElapsed.count() << std::endl;
        Cdata << gen << '\t' << c_sortElapsed.count() << '\n';

    
     /*test std::sort sort for 160000 random number*/
    auto STDstart = std::chrono::high_resolution_clock::now();
        std_sort(gen160000);
    auto STDend = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> std_sortElapsed = STDend - STDstart;
    std::cerr << "std::sort elapsed time[s] =" << std_sortElapsed.count() << std::endl;
        STDdata << gen << '\t' << std_sortElapsed.count() << '\n';
}