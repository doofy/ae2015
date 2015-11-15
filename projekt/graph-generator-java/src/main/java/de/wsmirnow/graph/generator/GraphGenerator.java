package de.wsmirnow.graph.generator;

import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import org.graphstream.algorithm.generator.BaseGenerator;
import org.graphstream.algorithm.generator.*;
import org.graphstream.graph.Edge;
import org.graphstream.graph.Graph;
import org.graphstream.graph.Node;
import org.graphstream.graph.implementations.SingleGraph;

public class GraphGenerator {

    public static void main(String[] args) {
        String filename = "testdata";
        int nodes = 1000;
        FileOutputStream fos = null;
        PrintWriter writer = null;
        try {
            fos = new FileOutputStream(filename);
            writer = new PrintWriter(new BufferedOutputStream(fos));
            generateTestdata(writer, nodes);
        } catch (FileNotFoundException ex) {
            System.err.printf(ex.getMessage());
        } finally {
            if (writer != null) {
                writer.flush();
                writer.close();
            }
            if (fos != null) {
                try {
                    fos.close();
                } catch (IOException ex) {
                    System.err.println(ex.getMessage());
                }
            }
        }
    }
    
    public static void generateTestdata(PrintWriter out, int nodes) {
        Graph graph = new SingleGraph("graph");
//        BaseGenerator gen = new LobsterGenerator();        
        BaseGenerator gen = new RandomGenerator(8, true, false);
//        BaseGenerator gen = new WattsStrogatzGenerator(1000, 8, 0.7);
//        BaseGenerator gen = new RandomEuclideanGenerator(2, false, false);
//        BaseGenerator gen = new DorogovtsevMendesGenerator();

        gen.addEdgeAttribute("weight");
        gen.setEdgeAttributesRange(1, 100);
        gen.addNodeAttribute("weight");
        gen.setNodeAttributesRange(1, 6);
        gen.addSink(graph);
        gen.begin();
        for (int i = 0; i < nodes; i++) {
            if (!gen.nextEvents()) {
                break;
            }
        }
        gen.end();
        graph.display(true);

        int n = graph.getNodeCount();
        int m = graph.getEdgeCount();
//        float mdivn = (float) m / n;
        
        out.println("Generated graph with RandomGenerator model");
        out.println(n);
        out.println(m);
        for (int i = 0; i < n; i++) {
            Node node = graph.getNode(i);
            out.println(Math.round((double)node.getAttribute("weight")));
        }
        for (int j = 0; j < m; j++) {
            Edge edge = graph.getEdge(j);
            out.printf("%s %s %d", 
                    edge.getNode0().getId(), 
                    edge.getNode1().getId(),  
                    Math.round((double)edge.getAttribute("weight")));
            if (j < m - 1) out.println();
        }
    }
}
