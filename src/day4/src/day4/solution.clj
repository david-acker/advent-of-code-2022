(ns day4.solution)

;; Part One
(defn -contains-super-set [[a-start a-end b-start b-end]] 
  (or 
   (and (<= a-start b-start) (>= a-end b-end))
   (and (<= b-start a-start) (>= b-end a-end))))

(defn get-super-set-ranges [input-data]
  (->> input-data 
       (filter -contains-super-set)
       (count)))