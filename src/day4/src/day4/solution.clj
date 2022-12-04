(ns day4.solution)

;; Part One
(defn -contains-super-set [[a-start a-end b-start b-end]] 
  (or 
   (and (<= a-start b-start) (>= a-end b-end))
   (and (<= b-start a-start) (>= b-end a-end))))

(defn get-superset-count [input-data]
  (->> input-data 
       (filter -contains-super-set)
       (count)))

;; Part Two
(defn -has-overlap [[a-start a-end b-start b-end]]
  (or
   (-contains-super-set [a-start a-end b-start b-end])
   (and 
    (>= a-start b-start) 
    (<= a-start b-end))
   (and
    (<= a-end b-end)
    (>= a-end b-start))))

(defn get-overlap-count [input-data]
  (->> input-data
       (filter -has-overlap)
       (count)))