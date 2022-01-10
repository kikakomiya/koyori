NAME=gtk-app
CXX=clang++
SRCFILES=src/main.cpp
CXXFLAGS=-I/usr/include/gtk-4.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/graphene-1.0 -I/usr/lib/graphene-1.0/include -lgtk-4 -lglib-2.0 -lgobject-2.0 -lgio-2.0

$(NAME): $(SRCFILES)
	$(CXX) $^ $(CXXFLAGS) -o $@

.PHONY clean:
	rm -rf $(NAME)