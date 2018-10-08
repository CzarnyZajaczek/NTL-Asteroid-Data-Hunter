#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>

//#include "catalina.h"
#include "alg1_psyho.h"
//#include "alg2_res1.h"
//#include "alg3_pfr.h"
//#include "alg4_nofto.h"
//#include "alg5_kushal1.h"

using namespace std;

struct SDetection
{
    double RA[4];
    double DEC[4];
    string imgID;
};

void doTrain(AsteroidDetector& my) {
	char buf[65536];
	while (true) {
		int W, H, N;
		if (!(cin >> W >> H)) {
			cin.clear();
			break;
		}
		vector<int> image[4];
		vector<string> header[4];
		vector<double> wcs[4];

		for (int f = 0; f < 4; f++) {
			image[f].resize(W * H);
			for (int i = 0; i < W * H; i++)
				cin >> image[f][i];
			cin >> N;
			cerr << "N=" << N << endl;
			cin.getline(buf, 65536);
			for (int i = 0; i < N; i++) {
				cin.getline(buf, 65536);
				header[f].push_back(buf);
			}
			wcs[f].resize(8);
			for (int i = 0; i < 8; i++) {
				cin >> wcs[f][i];
			}
		}
		vector<string> detections;
		cin >> N;
		cerr << "N=" << N << endl;
		cin.getline(buf, 65536);
		for (int i = 0; i < N; i++) {
			cin.getline(buf, 65536);
			detections.push_back(buf);
		}

		int v = my.trainingData(W, H, image[0], header[0], wcs[0], image[1],
				header[1], wcs[1], image[2], header[2], wcs[2], image[3],
				header[3], wcs[3], detections);
		cout << v << endl;
		cout.flush();
		if (v == 1)
			break;
	}
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
	// save the rf data
	my.saveRF();
}

void exampleFunction(AsteroidDetector& my) {
  int testvariable;
  testvariable=0;
}

void doTest(AsteroidDetector& my) {
//   fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
//   fprintf(stderr, "%d", __LINE__);
//   fprintf(stderr, "%s", "\n");
  exampleFunction(my);
	char buf[65536];
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
    while (true)
    {
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");

        int W,H,N;
        string ID;
	
        if (cin.getline(buf, 65536).eof()) {
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
        	break;
        }
	if (buf[0] == '=') {
		// the seperator
		continue;
	}
        cerr << "Running test case: " << buf << endl;

        ID = buf;
        cin >> W >> H;
        vector<int> image[4];
        vector<string> header[4];
        vector<double> wcs[4];

	cout <<"PROGRESS:0.2"<< endl;
        cerr << "S : W=" << W << " H=" << H << endl;
	double progress = 0.2;
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
        for (int f=0;f<4;f++)
        {
            image[f].resize(W*H);
            for (int i=0;i<W*H;i++)
                cin >> image[f][i];
            cin >> N;
            cerr << "S : N=" << N << endl;
            cin.getline(buf, 65536);
            for (int i=0;i<N;i++)
            {
                cin.getline(buf, 65536);
                header[f].push_back(buf);
            }
            wcs[f].resize(8);
            for (int i=0;i<8;i++)
            {
                cin >> wcs[f][i];
            }

            progress += (0.7 - 0.2) / 4;

	    cout <<"PROGRESS:"<<progress<<endl;
           cerr << "PROGRESS:" << progress << endl;
          cout.flush();
        }

  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
	cout <<"PROGRESS:0.7"<<endl;
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
        cin.getline(buf, 65536);
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
        int v = my.testingData(ID, W, H, image[0], header[0], wcs[0],
                                         image[1], header[1], wcs[1],
                                         image[2], header[2], wcs[2],
                                         image[3], header[3], wcs[3]);
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
      cout <<"PROGRESS:0.8"<<endl;
        cout << v << endl;
        cout.flush();
	
    }

  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
    vector<string> res = my.getAnswer();
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "\n");
    cout << res.size() << endl;
  fprintf(stderr, "%s", "algo/linux/main.cpp::doTest() line ");
  fprintf(stderr, "%d", __LINE__);
  fprintf(stderr, "%s", "  res.size() ");
  int res_size;
  res_size = res.size();
  fprintf(stderr, "%d", res_size);
  fprintf(stderr, "%s", "\n");
    for (int i=0; i < res.size(); i++)
        cout << res[i] << endl;
    cout.flush();
}

int main(int argc, char *argv[])
{
    AsteroidDetector my;
    char mode[1024];
    char RFFolder[1024];
    // set the default value
    snprintf(mode, sizeof(mode), "%s", "all");
    RFFolder[0] = 0;

    // read the command line parameters
    for (int i = 0; i < argc; i++) {
    	if (strcmp(argv[i], "--mode") == 0) {
    		snprintf(mode, sizeof(mode), "%s", argv[i + 1]);
    	} else if (strcmp(argv[i], "--folder") == 0) {
    		snprintf(RFFolder, sizeof(RFFolder), "%s", argv[i + 1]);
    	}
    }

    // set the RFFolder (maybe empty)
    my.RFFolder = RFFolder;

    if (0 == strcmp(mode, "all")) {
    	doTrain(my);
    	doTest(my);
    } else if (0 == strcmp(mode, "train")) {
    	doTrain(my);
    } else if (0 == strcmp(mode, "test")) {
    	doTest(my);
    }
    return 0;
}
