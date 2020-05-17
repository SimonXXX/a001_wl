pipeline {
    agent any
	stages {
        stage('Build') {
            steps {
                sh 'echo "this is the build"'
            }
        }

        stage('Test') {
            steps {
                sh ' g++ -std=c++17 -Wall -Werror -O2 -o test main.cpp Clexicon.cpp lexicon.cpp'
		sh 'chmod 700 test'
                sh './test'
            }
        }
	}
}
