(ns day2.core
  (:require [clojure.java.io :as io])
  (:require [day2.solution :as solution])
  (:require [day2.utils :as utils])
  (:gen-class))

(defn -calculate-part-one [input-data]
  (->> input-data
       (solution/get-total-score)
       (println "    Part one:")))

(defn -calculate-part-two [input-data]
  (println "    Part two:" "not yet implemented"))

(defn -main [& args]
  (let [file-name   (first args)
        file-exists (.exists (io/file file-name))]
    (if file-exists 
      (->> (utils/get-input-data file-name)
           (-calculate-part-one)
           (-calculate-part-two))
      (println "The specified file could not be found: " file-name))))