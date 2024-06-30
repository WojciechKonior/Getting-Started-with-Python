print("Hello World")

# Read CSV that file containing a list of students and their grades
import csv

class Students:
    def __init__(self, path):
        self.avr_grds = []
        self.read_scores_from_csv(path)


    def read_each_row(self, data):

        for row in data:
            avr_grds_num = 0
            for grd in row[1:]:
                avr_grds_num += int(grd)
            avr_grds_num /= 4
            
            # calucaltes the average grade for each student
            self.avr_grds.append((row[0], avr_grds_num))
        
        return self.avr_grds

    def output_highest_score(self, avr_grds):
        # outputs the student who scored above the class average
        max = 0.0
        std = ''
        for student in avr_grds:
            if student[1]>max:
                max = student[1]
                std = student[0]

        print(f"the maximum score gained {std} and it was {max}")

    def read_scores_from_csv(self, path):
        with open('/home/wkonior/Projects/programmingTrainings/interview/grades.csv', newline='') as csvfile:

            data = csv.reader(csvfile, delimiter=',', quotechar='|')
            avr_grds = self.read_each_row(data)
            self.output_highest_score(avr_grds)

