(ns day2.solution)

(defn -get-shape-score [your-pick]
  (condp = your-pick
    "X" 1
    "Y" 2
    "Z" 3))

(defn -is-same-shape [your-pick opponents-pick]
  (let [equivalence-map {"A" "X", ;; A (opponent's rock) is equivalent to X (your rock) 
                         "B" "Y", ;; B (opponent's paper) is equivalent to Y (your paper)
                         "C" "Z"  ;; C (opponent's scissors) is equivalent to Z (your scissors)
                         }]
    (= your-pick (get equivalence-map opponents-pick))))

(defn -get-outcome [opponents-pick your-pick]
  (let [strategy-map {
                      "A" "Y", ;; paper (Y) beats rock (A)
                      "B" "Z", ;; scissors (Z) beats paper (B)
                      "C" "X"  ;; rock (X) beats scissors (C)
                      }]
  (cond
    (= your-pick (get strategy-map opponents-pick)) :win
    (-is-same-shape your-pick opponents-pick) :tie
    :else :loss)))

(defn -get-outcome-score [outcome]
  (condp = outcome
    :win 6
    :tie 3
    :loss 0))

(defn get-score [opponents-pick your-pick]
  (let [outcome       (-get-outcome opponents-pick your-pick)
        outcome-score (-get-outcome-score outcome)
        shape-score   (-get-shape-score your-pick)]
    (+ outcome-score shape-score)))

(defn get-total-score [input-data]
  (->> input-data
       (map (fn [[opponents-pick your-pick]] (get-score opponents-pick your-pick)))
       (reduce +)))