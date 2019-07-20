#-*- coding: utf-8 -*-
import logging
import os

from gensim.models import word2vec

logging.basicConfig(format='%(asctime)s : %(levelname)s : %(message)s', level=logging.INFO)

DATA_DIR = os.path.join(os.path.dirname(__file__), "data")
sentences = word2vec.Text8Corpus(os.path.join(DATA_DIR, "text8"), 50)
model = word2vec.Word2Vec(sentences, size=300, min_count=30)

model.init_sims(replace=True)
model.save("word2vec_gensim.bin")
model = word2vec.Word2Vec.load("word2vec_gensim.bin")

