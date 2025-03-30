
import matplotlib
matplotlib.use('TkAgg')  # or 'Agg' for non-interactive backend
import matplotlib.image as mpi
import matplotlib.pyplot as plt
import numpy as np

def showImage():
    imagem0 = mpi.imread("polarbear.jpg")

    # Create a figure and set up an event handler for keyboard events
    fig, ax = plt.subplots()

    plt.imshow(imagem0)
    plt.axix('off')

    # Define a function to close the figure on keypress
    def on_key(event):
        if event.key == 'q':  # Press 'q' to close the image
            plt.close(fig)  # Close the figure window

    # Connect the keypress event to the figure
    fig.canvas.mpl_connect('key_press_event', on_key)

    plt.show()

    return imagem0

# the "channel" parameter stands for which color panel to enhance: 1-Red; 2-Grenn; 3-Blue
# the "factor" parameter stands for the intensity of the pixel(s) in question: < 1 for darker and > 1 for brighter
def enhanceChannel(name, factor, channel):
    imagem0 = mpi.imread("polarbear.jpg")
    imagem1 = imagem0.copy()
    imagem1 = imagem1.astype(np.float32)
    imagem1[:,:,channel] *= factor
    imagem1 = imagem1.clip(0, 255)
    imagem1 = imagem1.astype(np.uint8)

    plt.imshow(imagem1)
    plt.axis('off')
    plt.show()
    
    return imagem1

question = str(input("Want to enhance? [Y/N] "))
while(question.lower() != 'n'):
    pallete = int(input("0 - red\n1 - green\n2 - blue\n-->"))
    intensity = int(input("values greater than 1 for brighter and lesser than 1 for darker: "))
    enhanceChannel("polarbear.jpg", intensity, pallete)
    question = str(input("Want to enhance? [Y/N] "))