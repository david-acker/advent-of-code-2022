(ns day2.utils
  (:require [clojure.string :as string]))

(defn get-input-data 
  "Gets the input data from the specified file."
  [file-path]
  (->> (slurp file-path)
       (string/split-lines)
       (map #(string/split % #" "))))