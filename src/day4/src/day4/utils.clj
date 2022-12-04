(ns day4.utils
  (:require [clojure.string :as string]))

(defn -split [line]
  (->> (string/split line #",")
       (map #(string/split % #"\-"))
       (flatten)))

(defn -parse-line [line]
  (->> (-split line)
       (map #(Integer/parseInt %))))

(defn get-input-data [file-path]
  (->> (slurp file-path)
       (string/split-lines)
       (map -parse-line)))