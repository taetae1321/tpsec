% Facts (symptoms for different patients)
symptom(rohan, sore_throat).
symptom(rohan, cough).
symptom(rohan, fever).

symptom(sara, itchy_eyes).
symptom(sara, runny_nose).
symptom(sara, sneezing).

symptom(ankit, chest_pain).
symptom(ankit, shortness_of_breath).
symptom(ankit, fatigue).

% Rules for diseases
disease(Patient, strep_throat) :- 
    symptom(Patient, sore_throat),
    symptom(Patient, cough),
    symptom(Patient, fever).

disease(Patient, allergy) :- 
    symptom(Patient, itchy_eyes),
    symptom(Patient, runny_nose),
    symptom(Patient, sneezing).

disease(Patient, heart_disease) :- 
    symptom(Patient, chest_pain),
    symptom(Patient, shortness_of_breath),
    symptom(Patient, fatigue).

% Example usage:
% To find the disease for any patient:
% ?- disease(Patient, Disease).