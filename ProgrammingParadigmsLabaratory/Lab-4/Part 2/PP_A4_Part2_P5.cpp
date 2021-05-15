#include <iostream>
using namespace std;

class Cricketer
{
protected:
    string fName;
    string lName;
    string country;
    string role;
    int nMatches;
    int jNum;
    string *pCountries;

public:
    Cricketer();
    Cricketer(string, string, string, string, int, int);
    virtual ~Cricketer();

    void setCricketerDetails();
    void displayCricketerDetails();
};

class Batsmen : virtual public Cricketer
{
protected:
    int *runs;
    char batHType;
    float sRate;

public:
    Batsmen();
    Batsmen(int *, char, float, string, string, string, string, int, int);
    ~Batsmen();

    void setBatsmenDetails();
    void displayBatsmenDetails();
};

class Bowler : virtual public Cricketer
{
protected:
    int *wickets;
    char bowHType;
    string bType;

public:
    Bowler();
    Bowler(int *, char, string, string, string, string, string, int, int);
    ~Bowler();

    void setBowlerDetails();
    void displayBowlerDetails();
};

class AllRounder : public Batsmen, public Bowler
{
public:
    AllRounder();
    AllRounder(int *, char, float, int *, char, string, string, string, string, string, int, int);
    ~AllRounder();

    void insertRecords();
    float calBattingAverage();
    int calTotalWickets();
    int highestWicketsTakenCountry();
    int highestRunsScoredCountry();
    void setAllRounderDetails();
    void displayAllRounderDetails();
};

int main()
{
    AllRounder one;
    one.setAllRounderDetails();
    one.insertRecords();
    one.displayAllRounderDetails();

    return 0;
}

Cricketer ::Cricketer()
{
    cout << "Cricket Constructor" << endl;
}

Cricketer ::Cricketer(string f, string l, string c, string r, int n, int j) : fName(f), lName(l), country(c), role(r), nMatches(n), jNum(j)
{
    cout << "Cricketer Parameterized Constructor" << endl;
}

Cricketer ::~Cricketer()
{
    cout << "Cricketer Destructor" << endl;
}

void Cricketer ::setCricketerDetails()
{
    string f, l, c, r;
    int n, j;

    cout << "\n";
    cout << "Enter First Name: - ";
    cin >> f;
    cout << "Enter Last Name: - ";
    cin >> l;
    cout << "Enter Cricketer's Country: - ";
    cin >> c;
    cout << "Enter Role: - ";
    cin >> r;
    cout << "Enter Number of Matches Played: - ";
    cin >> n;
    cout << "Enter Jersey Number: - ";
    cin >> j;
    pCountries = new string[n];
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Match " << i + 1 << " Played against Country: - ";
        cin >> pCountries[i];
    }
    cout << "\n";

    fName = f;
    lName = l;
    country = c;
    role = r;
    nMatches = n;
    jNum = j;
}

void Cricketer ::displayCricketerDetails()
{
    cout << "\n";
    cout << "Name: - " << fName << " " << lName << endl;
    cout << "Cricketer's Country: - " << country << endl;
    cout << "Role: - " << role << endl;
    cout << "Number of Matches Played: - " << nMatches << endl;
    cout << "Jersey Number: - " << jNum << endl;
    cout << "\n";
}

Batsmen ::Batsmen()
{
    cout << "Batsmen Constructor" << endl;
}

Batsmen ::Batsmen(int *r, char bht, float s, string f, string l, string c, string ro, int n, int j) : runs(r), batHType(bht), sRate(s), Cricketer(f, l, c, ro, n, j)
{
    cout << "Batsmen Parameterized Constructor" << endl;
}

Batsmen ::~Batsmen()
{
    delete runs;
    runs = NULL;

    cout << "Batsmen Destructor" << endl;
}

void Batsmen ::setBatsmenDetails()
{
    char bh;
    float sr;

    Cricketer::setCricketerDetails();
    cout << "Enter Batting Hand: - ";
    cin >> bh;
    cout << "Enter Strike Rate: - ";
    cin >> sr;

    batHType = bh;
    sRate = sr;

    Batsmen::runs = new int[Cricketer::nMatches];

    cout << "\n";
    for (int i = 0; i < Cricketer::nMatches; i++)
    {
        int x;

        cout << "Runs Scored in Match " << i + 1 << ": - ";
        cin >> x;

        Batsmen::runs[i] = x;
    }
}

void Batsmen ::displayBatsmenDetails()
{
    cout << "\n";
    Cricketer::displayCricketerDetails();
    cout << "Batting Hand: - " << batHType << endl;
    cout << "Strike Rate: - " << sRate << endl;
    cout << "\n";
}

Bowler ::Bowler()
{
    cout << "Bowler Constructor" << endl;
}

Bowler ::Bowler(int *w, char boht, string b, string f, string l, string c, string ro, int n, int j) : wickets(w), bowHType(boht), bType(b), Cricketer(f, l, c, ro, n, j)
{
    cout << "Bowler Parameterized Constructor" << endl;
}

Bowler ::~Bowler()
{
    delete wickets;
    wickets = NULL;

    cout << "Bowler Destructor" << endl;
}

void Bowler ::setBowlerDetails()
{
    char bh;
    string bt;

    cout << "\n";
    Cricketer::setCricketerDetails();
    cout << "Enter Bowling Hand: - ";
    cin >> bh;
    cout << "Enter Bowling Type: - ";
    cin >> bt;
    cout << "\n";

    bowHType = bh;
    bType = bt;

    Bowler::wickets = new int[Cricketer::nMatches];

    cout << "\n";
    for (int i = 0; i < Cricketer::nMatches; i++)
    {
        int y;

        cout << "Wickets Taken in Match " << i + 1 << ": - ";
        cin >> y;

        Bowler::wickets[i] = y;
    }
}

void Bowler ::displayBowlerDetails()
{
    Cricketer::displayCricketerDetails();
    cout << "Bowling Hand: - " << bowHType << endl;
    cout << "Bowling Type: - " << bType << endl;
    cout << "\n";
}

AllRounder ::AllRounder()
{
    cout << "AllRounder Constructor" << endl;
}

AllRounder ::AllRounder(int *r, char bht, float s, int *w, char boht, string b, string f, string l, string c, string ro, int n, int j) : Batsmen(r, bht, s, f, l, c, ro, n, j), Bowler(w, boht, b, f, l, c, ro, n, j), Cricketer(f, l, c, ro, n, j)
{
    cout << "AllRounder Parameterized Constructor" << endl;
}

AllRounder ::~AllRounder()
{
    cout << "AllRounder Destructor" << endl;
}

void AllRounder ::insertRecords()
{
    Batsmen::runs = new int[Cricketer::nMatches];
    Bowler::wickets = new int[Cricketer::nMatches];

    cout << "\n";
    for (int i = 0; i < Cricketer::nMatches; i++)
    {
        int x, y;

        cout << "Runs Scored in Match " << i + 1 << ": - ";
        cin >> x;
        cout << "Wickets Taken in Match " << i + 1 << ": - ";
        cin >> y;

        Batsmen::runs[i] = x;
        Bowler::wickets[i] = y;
    }
}

float AllRounder ::calBattingAverage()
{
    double avg = 0;

    for (int i = 0; i < Cricketer::nMatches; i++)
    {
        avg = avg + Batsmen::runs[i];
    }

    avg = avg / Cricketer::nMatches;

    cout << "\n";
    cout << "Batting Average: - " << avg << endl;

    return avg;
}

int AllRounder ::calTotalWickets()
{
    int wick = 0;

    for (int i = 0; i < Cricketer::nMatches; i++)
    {
        wick = wick + Bowler::wickets[i];
    }

    cout << "\n";
    cout << "Total Wickets: - " << wick << endl;

    return wick;
}

int AllRounder ::highestWicketsTakenCountry()
{
    int wick = Bowler::wickets[0];

    for (int i = 1; i < Cricketer::nMatches; i++)
    {
        if (wick < Bowler::wickets[i])
        {
            wick = Bowler::wickets[i];
        }
    }

    for (int i = 1; i < Cricketer::nMatches; i++)
    {
        if (wick == Bowler::wickets[i])
        {
            cout << "\n";
            cout << "Highest Wickets Taken " << wick << " against country " << Cricketer::pCountries[i] << endl;
            break;
        }
    }

    return wick;
}

int AllRounder ::highestRunsScoredCountry()
{
    int run = Batsmen::runs[0];

    for (int i = 1; i < Cricketer::nMatches; i++)
    {
        if (run < Batsmen::runs[i])
        {
            run = Batsmen::runs[i];
        }
    }

    for (int i = 0; i < Cricketer::nMatches; i++)
    {
        if (run == Batsmen::runs[i])
        {
            cout << "\n";
            cout << "Highest Runs Scores " << run << " against country " << Cricketer::pCountries[i] << endl;
            break;
        }
    }

    return run;
}

void AllRounder ::setAllRounderDetails()
{
    char bath, bowh;
    float sr;
    string bt;

    cout << "\n";
    Cricketer::setCricketerDetails();
    cout << "Enter Batting Hand: - ";
    cin >> bath;
    cout << "Enter Strike Rate: - ";
    cin >> sr;
    cout << "Enter Bowling Hand: - ";
    cin >> bowh;
    cout << "Enter Bowling Type: - ";
    cin >> bt;
    cout << "\n";

    batHType = bath;
    sRate = sr;
    bowHType = bowh;
    bType = bt;
}

void AllRounder ::displayAllRounderDetails()
{
    cout << "\n";
    cout << "Cricketer Details: -\n\n";
    Cricketer::displayCricketerDetails();
    cout << "Batting Hand: - " << Batsmen::batHType << endl;
    cout << "Strike Rate: - " << Batsmen::sRate << endl;
    cout << "Bowling Hand: - " << Bowler::bowHType << endl;
    cout << "Bowling Type: - " << Bowler::bType << endl;
    calBattingAverage();
    calTotalWickets();
    highestWicketsTakenCountry();
    highestRunsScoredCountry();
    cout << "\n";
}