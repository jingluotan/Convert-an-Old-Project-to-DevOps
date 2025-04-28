CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = linked_list_app
TEST_TARGET = unit_tests

all: build

build:
	@echo "building project"
	$(CXX) $(CXXFLAGS) main.cpp linked_list.cpp -o $(TARGET)
	@echo "✅ build complete"

test:
	@echo "🧪 running tests"
	$(CXX) $(CXXFLAGS) unit_tests.cpp -o $(TEST_TARGET)
	./$(TEST_TARGET)
	@echo "✅ tests complete"

clean:
	@echo "🧹 cleaning files"
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "✅ clean complete"

run:
	@echo "🚀 running linked list app"
	./$(TARGET)

build-deb:
	@echo "📦 building debian package"
	@chmod +x debBuild.sh
	@./debBuild.sh

lint-deb:
	@echo "🔍 linting debian package"
	@$(MAKE) build-deb
	@timeout 60 lintian linked-list-v1.0.0.deb || true
