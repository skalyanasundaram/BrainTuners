#include <iostream>
#include <map>

using namespace std;

int main()
{
    double downPayment, loanAmount;
    int months, records;

    while (true)
    {
        cin >> months >> downPayment >> loanAmount >> records;

        if (months < 0)
        {
            break;
        }

        std::map<int, double> monthRecords;
        int currentMonth = 0;
        for(int recordIndex = 0; recordIndex < records; recordIndex++) 
        {
            int month = 0;
            double depreciation = 0;
            cin >> month >> depreciation;

            if (month != 0 && ((currentMonth + 1 ) != month))
            {
                while ((currentMonth + 1) != month)
                {
                    monthRecords[currentMonth + 1] = monthRecords[currentMonth];
                    currentMonth++;
                }
            }
                
            monthRecords[month] = depreciation;
            currentMonth = month;
        }

        while(currentMonth <= months)
        {
            monthRecords[currentMonth+1] = monthRecords[currentMonth];
            currentMonth++;
        }

        double totalValue = loanAmount, bankValue = downPayment + loanAmount, emi = loanAmount / months;
        for(int month=0; month <= months; month++)
        {
            if (month)
            {
                totalValue -= emi;
            }

            bankValue -= (bankValue * monthRecords[month]);

            if (totalValue < bankValue)
            {
                cout << month << " month" << ((month != 1)? "s":"") << endl;
                break;
            }
        }

        monthRecords.clear();
    }
    return 0;
}
