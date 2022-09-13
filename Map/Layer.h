#ifndef LAYER_H
#define LAYER_H

// interface for all layer type: image- and tile layer

class Layer {
    public:
        virtual void Render() = 0;
        virtual void Update() = 0;
};

#endif // LAYER_H
