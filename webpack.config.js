const path = require('path');
const outputDir = path.join(__dirname, "build/");
const webpack = require('webpack');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const CleanWebpackPlugin = require('clean-webpack-plugin');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: path.resolve(__dirname, 'lib/js/examples/Index.bs.js'),
  mode: 'development',
  resolve: {
    modules: [path.resolve(__dirname, 'src'), path.resolve(__dirname, 'node_modules')]
  },
  output: {
    // path: outputDir,
    // publicPath: outputDir,
    publicPath: '/',
    filename: 'Index.bs.js',
  },
  devtool: 'inline-source-map',
  devServer: {
    // contentBase: outputDir,
    port: 9000,
    hot: true,
    // publicPath: outputDir,
    // index: 'index.html'
    inline: true,
    historyApiFallback: true
  },
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /(node_modules)/,
        use: {
          loader: "babel-loader",
          options: {
            presets: [
              "@babel/preset-env",
              "@babel/preset-flow",
              "@babel/preset-react"
            ]
          }
        }
      }
    ]
  },
  plugins: [
    new CleanWebpackPlugin([outputDir]),
    new HtmlWebpackPlugin({
      title: 'Hot Module Replacement',
      template: 'examples/index.html',
    }),
    new webpack.HotModuleReplacementPlugin()
  ]
};