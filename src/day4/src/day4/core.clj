(ns day4.core
  (:require [clojure.java.io :as io])
  (:require [day4.solution :as solution])
  (:require [day4.utils :as utils])
  (:gen-class))

(defn -calculate-part-one [input-data]
  (->> input-data
       (solution/get-superset-count)
       (println "    Part one: ")))

(defn -calculate-part-two [input-data] 
  (->> input-data
       (solution/get-overlap-count)
       (println "    Part two: ")))

(defn -main [& args]
  (let [file-name   (first args)
        file-exists (.exists (io/file file-name))]
    (if file-exists
      (let [input-data (utils/get-input-data file-name)]
        (-calculate-part-one input-data)
        (-calculate-part-two input-data))
      (println "The specified file could not be found: " file-name))))