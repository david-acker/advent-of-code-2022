(ns day2.solution)

;; Part One
(defn -get-shape-score [your-pick]
  (condp = your-pick
    "X" 1
    "Y" 2
    "Z" 3
    ))

(defn -get-equivalent-shape [opponents-pick]
  (condp = opponents-pick
    "A" "X", ;; A (opponent's rock) is equivalent to X (your rock) 
    "B" "Y", ;; B (opponent's paper) is equivalent to Y (your paper)
    "C" "Z"  ;; C (opponent's scissors) is equivalent to Z (your scissors) 
    ));

(defn -is-same-shape [your-pick opponents-pick]
    (= your-pick (-get-equivalent-shape opponents-pick)))

(defn -get-winning-strategy [opponents-pick]
  (condp = opponents-pick
    "A" "Y", ;; paper (Y) beats rock (A)
    "B" "Z", ;; scissors (Z) beats paper (B)
    "C" "X"  ;; rock (X) beats scissors (C)
    ))

(defn -get-losing-strategy [opponents-pick]
  (condp = opponents-pick
    "A" "Z", ;; rock (A) beats scissors (Z)
    "B" "X", ;; paper (B) beats rock (X)
    "C" "Y"  ;; scissors (C) beats paper (Y))
    ))

(defn -get-outcome [opponents-pick your-pick]
  (cond
    (= your-pick (-get-winning-strategy opponents-pick)) :win
    (-is-same-shape your-pick opponents-pick) :tie
    :else :loss))

(defn -get-outcome-score [outcome]
  (condp = outcome
    :win 6
    :tie 3
    :loss 0
    ))

(defn -get-score-part-one [opponents-pick your-pick]
  (let [outcome       (-get-outcome opponents-pick your-pick)
        outcome-score (-get-outcome-score outcome)
        shape-score   (-get-shape-score your-pick)]
    (+ outcome-score shape-score)))

(defn get-total-score-part-one [input-data]
  (->> input-data
       (map (fn [[opponents-pick your-pick]] (-get-score-part-one opponents-pick your-pick)))
       (reduce +)))

;; Part Two
(defn -get-required-outcome [second-col]
  (condp = second-col
    "X" :loss
    "Y" :tie
    "Z" :win
    ))

(defn -get-required-shape [opponents-pick, outcome]
  (condp = outcome
    :win (-get-winning-strategy opponents-pick)
    :tie (-get-equivalent-shape opponents-pick)
    :loss (-get-losing-strategy opponents-pick)
    ))

(defn -get-score-part-two [opponents-pick second-col]
  (let [outcome        (-get-required-outcome second-col)
        outcome-score  (-get-outcome-score outcome)
        required-shape (-get-required-shape opponents-pick outcome)
        shape-score    (-get-shape-score required-shape)]
    (+ outcome-score shape-score)))

(defn get-total-score-part-two [input-data]
  (->> input-data
       (map (fn [[opponents-pick second-col]] (-get-score-part-two opponents-pick second-col)))
       (reduce +)))