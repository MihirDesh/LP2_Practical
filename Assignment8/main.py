class Employee:
    def __init__(self, name, productivity, quality, teamwork, communication, initiative, adaptability):
        self.name = name
        self.productivity = productivity
        self.quality = quality
        self.teamwork = teamwork
        self.communication = communication
        self.initiative = initiative
        self.adaptability = adaptability

class PerformanceEvaluator:
    def __init__(self):
        self.criteria_weights = {
            'productivity' : 1,
            'quality' : 1,
            'teamwork' : 1,
            'communication' : 1,
            'initiative' : 1,
            'adaptability' : 1
        }
    
    def evaluate_performance(self, employee):
        overall_score = 0
        for criterion, weight in self.criteria_weights.items():
            overall_score += getattr(employee, criterion) * weight
        average = overall_score / 6
        if average >= 85:
            performance_level = "Exceptional"
        elif average >= 70:
            performance_level = "High"
        elif average >= 50:
            performance_level = "Medium"
        else:
            performance_level = "Low"
        return performance_level
    
if __name__ == "__main__":
    evaluator = PerformanceEvaluator()
    employee1 = Employee(name="John Doe", productivity=70, quality=45, teamwork=60, communication=32, initiative=55, adaptability=60)
    performance_level = evaluator.evaluate_performance(employee1)
    print(f"{employee1.name}'s performance level: {performance_level}")