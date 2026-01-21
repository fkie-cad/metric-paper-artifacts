# metric-artifacts

This is the artifact repository to the paper `To GOTO or Not to GOTO: Measuring Structural Complexity of (Decompiled) Code`

It contains all code samples used for the study as well as the questionnaires, scoring system, and collected participant data.
Remark: The files `results-survey_A.csv` and `results-survey_B.csv` contain the raw responses from each participant. 
Since some answers were not in English, all responses are translated to english in `result_evaluation_with_points.csv` for consistency.

Furthermore, these artifacts contain a small skript `validate_semantic_equivalence.py` to validate the semantic equivalence of the samples.
We updated the return-value to compare the number of times the function `foo` is called respectively the number of times `X` is printed.
Therefore, we replaced the function call and the print-statement with a counter.