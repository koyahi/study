# -*- coding: utf-8 -*-
import os
import keras
from keras.models import Sequential
from keras.layers.convolutional import Conv2D, MaxPooling2D
from keras.layers.core import Activation, Flatten, Dropout, Dense
from keras.datasets import mnist
from keras.optimizers import Adam
from keras.callbacks import TensorBoard

def lenet(input_shape, num_classes):
    model = Sequential()
    model.add(Conv2D(20, kernel_size=5, padding="same",
                     input_shape=input_shape, activation="relu"))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Conv2D(50, kernel_size=5, padding="same",
                     activation="relu"))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Flatten())
    model.add(Dense(500, activation="relu"))
    model.add(Dense(num_classes))
    model.add(Activation("softmax"))
    return model
